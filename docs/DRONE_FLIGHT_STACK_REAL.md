# Drone Flight Stack (Real hardware) — Overview

Purpose: Describe the real Pi + Pixhawk (ArduPilot) stack that mirrors the simulation.

## 1. High-level purpose
- Hardware: Raspberry Pi 5 (companion) + Pixhawk (ArduPilot FCU).
- Pipeline:
  - Camera (USB/V4L2) publishes `/image_raw` + `/camera_info`.
  - `apriltag_ros` publishes `/detections` (AprilTagDetectionArray).
  - `apriltag_pnp_broadcaster.py` (from `tag_hover_sim`) consumes detections + camera info, runs `solvePnP`, broadcasts TF `camera -> tag36h11:<id>`.
  - `hover_yaw_search.py` consumes TF + `/mavros/state`, publishes velocity setpoints `/mavros/setpoint_velocity/cmd_vel_unstamped` (and `/hover_yaw_cmd` debug).
  - MAVROS forwards setpoints to Pixhawk over serial (e.g., `serial:///dev/ttyAMA0:57600`).
  - Modes: SEARCH = constant yaw; LOCK = yaw P-control on tag TF.

## 2. Directory and file map (real hardware stack)
Assume home is `/home/<user>`.

- `~/harmonic_ws/src/tag_hover_sim/`
  - `tag_hover_sim/hover_yaw_search.py` — controller node.
  - `tag_hover_sim/apriltag_pnp_broadcaster.py` — PnP TF broadcaster.
  - `tag_hover_sim/tag_overlay.py` — debug overlay.
  - `launch/sim_lockon_backbone.launch.py` — launches MAVROS + controller (use correct params; avoid duplicate MAVROS).
  - `config/apriltag_params.yaml` — detector config (installed under `install/tag_hover_sim/share/tag_hover_sim/config/`).
  - Models/worlds are for sim; on hardware only the nodes/configs are used.

- `~/ardupilot/`
  - Upstream ArduPilot firmware and tools (used for SITL and building).

- MAVROS
  - System package (`mavros`); launch separately or via `sim_lockon_backbone.launch.py`.
  - Use unique `__node`/`namespace` if multiple MAVROS instances; typically only one for the FCU link.

## 3. Bringup steps (real hardware, headless)
1) Start MAVROS with serial FCU URL (example):  
   `ros2 launch mavros apm.launch fcu_url:=serial:///dev/ttyAMA0:57600`
2) Start camera driver (e.g., v4l2_camera) publishing `/image_raw` + `/camera_info`.
3) Start apriltag detector:  
   `ros2 run apriltag_ros apriltag_node --ros-args --params-file <path>/apriltag_params.yaml -r image:=/image_raw -r camera_info:=/camera_info`
4) Start PnP TF broadcaster:  
   `ros2 run tag_hover_sim apriltag_pnp_broadcaster --ros-args -p camera_frame:=camera -p tag_prefix:=tag36h11 -p tag_size_m:=0.0376`
5) Start controller:  
   `ros2 run tag_hover_sim hover_yaw_search --ros-args -p mode:=SEARCH`
6) Arm and fly via RC/QGC/MAVProxy; set GUIDED/LOITER; SEARCH will spin until tag seen, LOCK will hold yaw on tag.

## 4. Notes and cautions
- Ensure only one MAVROS is running in the ROS domain to avoid type clashes.
- Align tag size between `apriltag_params.yaml` and `apriltag_pnp_broadcaster` (`tag_size_m`).
- If TF is noisy, consider smoothing in the PnP broadcaster.
- LOCK only controls yaw; no position hold logic beyond what the FCU provides.
