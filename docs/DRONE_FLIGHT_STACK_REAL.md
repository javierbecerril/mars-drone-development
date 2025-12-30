# Drone Flight Stack (Real hardware) — Overview

This document describes the real drone flight stack running on a Raspberry Pi 5 companion computer paired with an ArduPilot Pixhawk flight controller (FCU). It summarizes the current workspace implementation, files, topics, and run instructions so another engineer can pick up the project quickly.

## 1. High-level purpose

- Hardware: Raspberry Pi 5 (companion computer) + Pixhawk (ArduPilot) as flight controller.
- Overall pipeline (real drone):
  - Camera (USB, V4L2) captures images → publishes `/image_raw` and `/camera_info`.
  - AprilTag detector (`apriltag_ros`) processes rectified images and publishes detections on `/detections` (apriltag_msgs/AprilTagDetectionArray).
  - PnP-based TF broadcaster (`~/apriltag_pnp_broadcaster.py`) consumes `/camera_info` + `/detections`, runs OpenCV `solvePnP`, and publishes TF frames `camera` → `tag36h11:<id>`.
  - hover + yaw-search controller (`tag_hover_controller/hover_yaw_search.py`) listens to TF (`camera` → `tag36h11:0`) and `/mavros/state` and publishes velocity setpoints to MAVROS on `/mavros/setpoint_velocity/cmd_vel_unstamped` (geometry_msgs/Twist).
  - MAVROS forwards setpoints to Pixhawk over serial (e.g. `serial:///dev/ttyAMA0:57600`).
- Purpose: perform an AprilTag-guided yaw-search and lock behavior and optionally record imagery for vibration/structural analysis while holding hover.

## 2. Directory and file map (real hardware stack)

Paths below are relative to the Pi home (`/home/mars`) unless otherwise noted.

- ~/ros2_ws/src/tag_hover_controller/
  - Purpose: ROS 2 package implementing the hover + yaw-search controller.
  - Key files:
    - `tag_hover_controller/hover_yaw_search.py` (entry point)
      - Node name: `hover_yaw_search` (rclpy node)
      - Subscribes: `/mavros/state` (mavros_msgs/State)
      - Uses TF: looks up transform from `camera` → `tag36h11:0`
      - Publishes: `/hover_yaw_cmd` (geometry_msgs/Twist) [debug], `/mavros/setpoint_velocity/cmd_vel_unstamped` (geometry_msgs/Twist) [to FCU]
      - Declared ROS parameters (in node): `mode` (SEARCH/LOCK), `rate_hz`, `search_yaw`, `lock_k_yaw`, `camera_frame`, `tag_frame`, `max_yaw_rate`.
      - Behavior: SEARCH = constant yaw (search_yaw), LOCK = use TF to compute yaw_error ≈ atan2(x,z), apply P gain `lock_k_yaw` and clamp by `max_yaw_rate`.
    - `launch/lockon_backbone.launch.py`
      - Declares `fcu_url` and `mode` launch arguments.
      - Launches `mavros_node` (package `mavros`) and `hover_yaw_search`.
      - Note: this launch file sets some parameter names that do not match the node's declared parameter names (e.g. `search_yaw_rate` vs node's `search_yaw`, `lock_kp` vs `lock_k_yaw`). This mismatch is important and documented below.
    - `package.xml`, `setup.py`, `setup.cfg`, and resource files for packaging.

- ~/apriltag_pnp_broadcaster.py
  - Purpose: Standalone Python rclpy node that subscribes to `/camera_info` and `/detections` (apriltag_msgs/AprilTagDetectionArray), runs OpenCV `solvePnP` (IPPE square, fallback to ITERATIVE), and broadcasts TF transforms using `tf2_ros.TransformBroadcaster`.
  - Key parameters declared at runtime (via `declare_parameter`): `camera_frame` (default `camera`), `tag_prefix` (default `tag36h11`), `tag_size_m` (default 0.162 in the script; note: architecture doc uses 0.0376), `detections_topic` (default `/detections`), `camera_info_topic` (default `/camera_info`).
  - Output: TF frames named `tag36h11:<id>` with parent `camera`.
  - Notes: This script currently publishes raw solvePnP poses; there is no temporal smoothing in the broadcaster yet.

- ~/apriltag_tf_broadcaster.py
  - Purpose: Lightweight TF relay that reads detection messages which already contain pose(s) and republishes them as TF frames `tag36h11:<id>`.
  - Behavior: Tolerant to a number of detection message layouts (PoseStamped, PoseWithCovarianceStamped, Pose), extracts pose + header, and broadcasts TF accordingly.

- ~/tag_overlay.py
  - Purpose: Visual debugging node that subscribes to `/image_raw` and `/detections`, draws polylines and labels for tags, and publishes an overlay image on `/image_with_tags` (sensor_msgs/Image). Useful for `image_view` or `rqt_image_view` during bench testing.

- ~/apriltag_params.yaml
  - Purpose: Parameter file used when launching the apriltag ROS node (`apriltag_ros`).
  - Current content (important values):
    - `family: 36h11`
    - `tag_size: 0.0376` (meters)
    - `publish_tf: true` (note: PnP broadcaster is preferred for stable poses)
    - `z_up: false`

- ~/drone-project/
  - Subfolders present (all currently empty): `camera/`, `config/`, `logs/`, `mav/`, `sim/`.
  - Intended purpose:
    - `camera/` — calibration data / capture scripts
    - `config/` — runtime configs for Pi and FCU
    - `logs/` — recorded bag files, runs
    - `mav/` — mavlink/MAVProxy helpers or PX4/ArduPilot helpers
    - `sim/` — simulation helpers or SITL scenarios
  - Current state: empty; no files found in these folders in the workspace snapshot.

- ~/ardupilot/ (high level)
  - Purpose: upstream ArduPilot firmware sources and tools.
  - How you typically use it:
    - Use ArduPilot SITL or QGroundControl for testing; the repo contains many build/run scripts. For real hardware, build/flash firmware and configure parameters via QGC/MAVProxy. This workspace does not contain a custom ArduPilot build setup for the Pi — it is the upstream repo clone.

- MAVROS-related files in the workspace
  - The controller's `launch/lockon_backbone.launch.py` launches the `mavros_node` and provides a `fcu_url` launch argument (default `serial:///dev/ttyAMA0:57600`).
  - No other project-provided MAVROS launch/config files were found under `~/ros2_ws` in the workspace snapshot. The system uses the system-installed `mavros` package and its default plugins.

## 3. ROS 2 graph on the real drone (nodes, topics, params)

Below is the canonical graph for the real-hardware pipeline this workspace implements.

- Camera node: **Intel RealSense D455** via `v4l2_camera_node`
  - Publishes:
    - `/image_raw` (sensor_msgs/Image)
    - `/camera_info` (sensor_msgs/CameraInfo)
  - Frame_id: `camera`
  - Resolution: **1280×720** @ 30 FPS (YUYV → rgb8 encoding)
  - Consumes camera calibration file: `~/.ros/camera_info/camera_1280x720.yaml`
  - Important parameters: `video_device` (/dev/video4), `image_size` ([1280,720]), `pixel_format` (YUYV), `output_encoding` (rgb8), `frame_id` (camera), `camera_info_url`.

- AprilTag detector (`apriltag_ros`)
  - Subscribes: `/image_raw` (rectified image) and `/camera_info`.
  - Publishes: `/detections` (apriltag_msgs/AprilTagDetectionArray)
  - Uses: `~/apriltag_params.yaml` for family and tag size.

- PnP TF broadcaster (`apriltag_pnp_broadcaster.py`)
  - Script: `/home/mars/apriltag_pnp_broadcaster.py` (rclpy node)
  - Subscribes: `/camera_info` (sensor_msgs/CameraInfo), `/detections` (AprilTagDetectionArray)
  - Publishes: TF via `tf2_ros.TransformBroadcaster` — frames `camera` → `tag36h11:<id>`
  - Parameters in script:
    - `camera_frame` (default `camera`)
    - `tag_prefix` (default `tag36h11`)
    - `tag_size_m` (default 0.162 in script; verify with actual tag physical size and `apriltag_params.yaml`)
    - `detections_topic` (default `/detections`)
    - `camera_info_topic` (default `/camera_info`)

- Alternative TF broadcaster (`apriltag_tf_broadcaster.py`)
  - Script: `/home/mars/apriltag_tf_broadcaster.py`
  - Subscribes: `/detections`, extracts pose fields (supports multiple layouts), publishes TF frames `tag36h11:<id>`.

- Overlay node (`tag_overlay.py`)
  - Publishes: `/image_with_tags` (sensor_msgs/Image)
  - Subscribes: `/image_raw`, `/detections`
  - Parameters: `image_topic`, `detections_topic`, `output_topic`.

- MAVROS (`mavros_node` from system package)
  - Launch: via `ros2 launch mavros apm.launch.py fcu_url:=serial:///dev/ttyAMA0:57600` or via `lockon_backbone.launch.py` which creates a `mavros_node` node.
  - Publishes/Subscribes (relevant here):
    - Publishes: `/mavros/state` (mavros_msgs/State) as a topic the controller subscribes to.
    - Subscribes: `/mavros/setpoint_velocity/cmd_vel_unstamped` (geometry_msgs/Twist) to accept velocity setpoints.

- hover_yaw_search (controller)
  - Package: `tag_hover_controller`
  - Executable/entry point: `hover_yaw_search` (console script mapping to `hover_yaw_search.py`)
  - Subscribes: `/mavros/state` (mavros_msgs/State)
  - Looks up TF: `camera` → `tag36h11:0` (default `tag_frame` parameter)
  - Publishes: `/hover_yaw_cmd` (geometry_msgs/Twist) [debug], `/mavros/setpoint_velocity/cmd_vel_unstamped` (geometry_msgs/Twist) [to FCU]
  - Node parameters (as declared in the node source):
    - `mode` (SEARCH or LOCK) — default `SEARCH`
    - `rate_hz` (control loop frequency) — default 20.0
    - `search_yaw` (rad/s constant yaw in SEARCH) — default 0.25
    - `lock_k_yaw` (P gain for yaw in LOCK) — default 1.0
    - `camera_frame` (frame name for camera) — default `camera`
    - `tag_frame` (frame name for tag) — default `tag36h11:0`
    - `max_yaw_rate` (rad/s clamp) — default 0.6

Notes on parameter name mismatches
- The `launch/lockon_backbone.launch.py` file sets parameters named `search_yaw_rate` and `lock_kp` for `hover_yaw_search`, but the node declares parameters named `search_yaw` and `lock_k_yaw`. This mismatch means the launch file will not set the node's intended parameters unless corrected. The launch file also sets image width and other parameters that the node does not declare. This should be reconciled before relying on the launch file to tune the controller.

## 4. How to run the real-drone stack (step-by-step)

Below is a concrete typical run sequence for bench testing / real hardware. Adjust device names and file paths as needed.

1) Source ROS 2 and your workspace

```bash
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
```

2) Start camera node (Intel RealSense D455 via v4l2; exact command from hardware)

```bash
ros2 run v4l2_camera v4l2_camera_node --ros-args \
  -p video_device:=/dev/video4 \
  -p "image_size:=[1280, 720]" \
  -p time_per_frame.num:=1 -p time_per_frame.den:=30 \
  -p pixel_format:=YUYV -p output_encoding:=rgb8 \
  -p frame_id:=camera \
  -p camera_info_url:=file:///home/mars/.ros/camera_info/camera_1280x720.yaml
```

3) Start AprilTag detector

```bash
ros2 run apriltag_ros apriltag_node \
  --ros-args -p image_rect:=/image_raw -p camera_info:=/camera_info \
             --params-file /home/mars/apriltag_params.yaml
```

4) Start the PnP TF broadcaster (standalone script)

```bash
python3 ~/apriltag_pnp_broadcaster.py
```

(Alternative: run `python3 ~/apriltag_tf_broadcaster.py` if the detector already provides pose fields.)

5) (Optional) Start overlay for visual debugging

```bash
python3 ~/tag_overlay.py
# view with image_view or rqt_image_view
ros2 run image_tools showimage --ros-args -r image:=/image_with_tags
```

6) Start MAVROS connecting to Pixhawk (example serial URL)

```bash
ros2 launch mavros apm.launch.py fcu_url:=serial:///dev/ttyAMA0:57600
```

7) Start the hover controller in SEARCH or LOCK mode

```bash
# SEARCH mode
ros2 run tag_hover_controller hover_yaw_search --ros-args -p mode:=SEARCH -p rate_hz:=20.0

# LOCK mode (requires tag TF to be available)
ros2 run tag_hover_controller hover_yaw_search --ros-args -p mode:=LOCK -p rate_hz:=20.0
```

8) Sanity checks (use these to confirm the stack is running)

```bash
ros2 topic list
ros2 topic echo /detections
ros2 topic echo /mavros/state
ros2 topic echo /tf
ros2 topic echo /mavros/setpoint_velocity/cmd_vel_unstamped
```

Safety note: Always test with props removed or vehicle restrained, and verify `/mavros/state` indicates a connected FCU and a safe mode (e.g. GUIDED/LOITER) before enabling controller outputs.

## 5. Assumptions and limitations

Assumptions

- AprilTag family used: `tag36h11` (as set in `~/apriltag_params.yaml`).
- Tag physical size: `0.0376 m` in `apriltag_params.yaml` (verify that `apriltag_pnp_broadcaster.py` uses the same value via its `tag_size_m` parameter; it defaults to `0.162` in the script and should be reconciled).
- Camera target resolution: `1280×720` at 30 FPS (common values in launch/notes).
- TF naming: camera frame is `camera`, tag frames are `tag36h11:<id>` (e.g. `tag36h11:0`).
- Controller uses `/mavros/state` to gate publishing and expects the FCU to be in GUIDED/GUIDED_NOGPS/LOITER modes during bench tests.

Current limitations (from workspace and doc)

- Pose smoothing: `apriltag_pnp_broadcaster.py` publishes raw solvePnP poses (no temporal smoothing). This leads to noisy TFs; add an exponential smoother or small Kalman filter for control use.
- LOCK behavior: `hover_yaw_search` implements SEARCH mode robustly; LOCK mode yaw P-control is present but no active x/y/z position control (i.e., no range control or centering yet). The LOCK implementation falls back to SEARCH when TF is unavailable.
- Parameter naming mismatch: `launch/lockon_backbone.launch.py` uses parameter names that do not match the node's declared parameters (e.g. `search_yaw_rate` vs `search_yaw`, `lock_kp` vs `lock_k_yaw`). Fix the launch file or node parameter names for consistent tuning via launch.
- Packaging: Several helper scripts live at `~/` rather than packaged ROS 2 nodes. Packaging them would improve maintainability and allow `ros2 launch/ros2 run` usage consistently.
- Empty `drone-project/` folders: intended for calibration, logs, and sim scenarios but currently empty.

## 6. Recommended immediate next steps (practical)

- Reconcile tag size and parameter names:
  - Ensure `apriltag_pnp_broadcaster.py` `tag_size_m` matches `apriltag_params.yaml` (0.0376 m) or vice-versa.
  - Fix `launch/lockon_backbone.launch.py` to set the correct parameter names (e.g. `search_yaw` and `lock_k_yaw`) or change the node to accept the launch's param names.

- Add temporal smoothing to the PnP broadcaster:
  - Implement exponential smoothing on translation (`x,y,z`) and slerp/quaternion smoothing for rotation.
  - Expose a parameter `enable_pose_smoothing` and `pose_smoothing_alpha` so the smoothing can be tuned.

- Package the standalone scripts into ROS 2 packages or move them under `ros2_ws/src/` with entry points and add launch files that start the full stack.

- Implement/extend LOCK mode in `hover_yaw_search` to command small x/z velocities (range and centering) with safety clamps and deadbands.

---

If you want, I can now prepare a code patch for one of these immediate tasks (suggested order: 1) fix param/tag-size mismatches, 2) add smoothing to `apriltag_pnp_broadcaster.py`, 3) create a launch file to start the full stack). Tell me which you want and I'll prepare the patch and tests next.
