# tag_hover_sim

Simulation integration package for AprilTag hover/yaw-search stack in Gazebo Harmonic + ArduPilot SITL.

## Overview

This package mirrors the real Raspberry Pi 5 + Pixhawk drone stack (see `docs/DRONE_FLIGHT_STACK_REAL.md`) in a Gazebo Harmonic simulation environment with ArduPilot SITL.

Design principle: EXACT sim-to-real parity. The `sim_lockon_backbone.launch.py` file launches ONLY MAVROS + controller, just like the real hardware `lockon_backbone.launch.py`. Camera bridge, AprilTag detector, and PnP TF broadcaster are run in separate terminals in both environments.

**Architecture (both real and sim):**
```
Camera node (V4L2 on real; Gazebo bridge in sim)
   → /image_raw, /camera_info
   → apriltag_ros
   → /detections
   → apriltag_pnp_broadcaster
   → TF (camera → tag36h11:<id>)
   → hover_yaw_search
   → /mavros/setpoint_velocity/cmd_vel_unstamped
   → MAVROS
   → FCU (Pixhawk on real; ArduPilot SITL over UDP in sim)
```

## Prerequisites

- ROS 2 Jazzy
- Gazebo Harmonic
- ArduPilot SITL
- `ros_gz_bridge` package
- `apriltag_ros` package
- `mavros` package
- `tag_hover_sim` (this package) on the Pi for controller + PnP broadcaster

Install missing dependencies:

```bash
sudo apt install ros-jazzy-ros-gz-bridge ros-jazzy-mavros ros-jazzy-mavros-extras
```

## Build

```bash
cd ~/harmonic_ws
source /opt/ros/jazzy/setup.bash
colcon build --packages-select tag_hover_sim --symlink-install
source install/setup.bash
```

## Usage (Multi-terminal; matches real hardware)

1) **Gazebo Harmonic** (SIM ONLY)
```bash
gz sim drone_apriltag_world.sdf
```

2) **Camera Bridge** (SIM ONLY; replaces v4l2_camera_node from hardware)
```bash
source ~/harmonic_ws/install/setup.bash
ros2 run ros_gz_bridge parameter_bridge \
  /camera@sensor_msgs/msg/Image@gz.msgs.Image \
  /camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo \
  --ros-args -r /camera:=/image_raw
```
**CRITICAL:** Your Gazebo SDF camera sensor MUST be configured for **1280×720** resolution to match the Intel RealSense D455 hardware. Example SDF snippet:
```xml
<sensor name="camera" type="camera">
  <camera>
    <image>
      <width>1280</width>
      <height>720</height>
    </image>
    <clip><near>0.1</near><far>100</far></clip>
  </camera>
  <update_rate>30</update_rate>
</sensor>
```

3) **AprilTag Detector** (IDENTICAL)
```bash
ros2 run apriltag_ros apriltag_node \
  --ros-args -p image_rect:=/image_raw -p camera_info:=/camera_info \
  --params-file ~/harmonic_ws/src/tag_hover_sim/config/apriltag_params.yaml
```

4) **PnP TF Broadcaster** (IDENTICAL)
```bash
python3 ~/apriltag_pnp_broadcaster.py
```

5) **ArduPilot SITL** (SIM ONLY)
```bash
cd ~/ardupilot/ArduCopter
../Tools/autotest/sim_vehicle.py -v ArduCopter -f gazebo-iris --console --map
```

6) **MAVROS + Controller** (IDENTICAL structure)
```bash
source /opt/ros/jazzy/setup.bash
source ~/harmonic_ws/install/setup.bash
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py mode:=SEARCH
```

7) **Arm and takeoff** (in MAVProxy)
```bash
mode GUIDED
arm throttle
takeoff 2
```

8) **Observe controller behavior**
- SEARCH mode: constant yaw rotation at 0.25 rad/s
- Switch to LOCK mode: `ros2 param set /hover_yaw_search mode LOCK`

### Launch Arguments (sim_lockon_backbone.launch.py)

| Argument | Default | Description |
|----------|---------|-------------|
| `mode` | `SEARCH` | Controller mode: `SEARCH` or `LOCK` |
| `fcu_url` | `udp://:14540@127.0.0.1:14550` | MAVROS FCU connection URL |
| `gz_camera_topic` | — | (Camera bridge runs separately) |
| `gz_camera_info_topic` | — | (Camera bridge runs separately) |
| `pnp_broadcaster_script` | — | (PnP broadcaster runs separately) |

### Verification

Check that all nodes are running and topics are published:

```bash
# List all topics
ros2 topic list

# Expected topics:
# /image_raw
# /camera_info
# /detections
# /tf
# /mavros/state
# /mavros/setpoint_velocity/cmd_vel_unstamped
# /hover_yaw_cmd

# Check camera publishing
ros2 topic hz /image_raw

# Check AprilTag detections
ros2 topic echo /detections

# Check TF frames
ros2 run tf2_ros tf2_echo camera tag36h11:0

# Check controller output
ros2 topic echo /hover_yaw_cmd
```

## Configuration

### AprilTag Parameters

Edit `config/apriltag_params.yaml` to match your Gazebo world:

- `family`: AprilTag family (default: `36h11`)
- `tag_size`: Physical size in meters (default: `0.0376` m)
- `camera_frame`: Camera TF frame name (default: `camera`)

**Important:** Ensure `tag_size` matches the tag model size in your Gazebo SDF file.

### Controller Parameters

The `hover_yaw_search` node reads its own defaults (matching real hardware behavior). You can override `mode` via launch arg. Other parameters can be tuned at runtime using `ros2 param set`.

## Troubleshooting

### Camera not publishing

- Verify Gazebo is running and the camera sensor is active
- Check `gz_camera_topic` and `gz_camera_info_topic` match your SDF
- Inspect bridge logs: `ros2 topic echo /image_raw` should show messages

### MAVROS not connecting

- Verify SITL is running: `netstat -an | grep 14540`
- Check `fcu_url` in launch arguments
- Inspect MAVROS logs for connection errors

### AprilTag not detected

- Verify camera is publishing: `ros2 topic hz /image_raw`
- Check tag is visible in camera view
- Verify `tag_size` in `apriltag_params.yaml` matches Gazebo SDF
- Check AprilTag family matches (`36h11`)

### Controller not commanding

- Check `/mavros/state` shows `connected: true` and `mode: GUIDED`
- Verify TF is available: `ros2 run tf2_ros tf2_echo camera tag36h11:0`
- Check controller logs for TF lookup failures
- If real hardware launch file parameters seem ignored, see `docs/PARAMETER_MISMATCH_ISSUE.md`

## Files

- `launch/sim_lockon_backbone.launch.py` - Main simulation launch file
- `config/apriltag_params.yaml` - AprilTag detector configuration
- `package.xml` - ROS 2 package manifest
- `setup.py` - Python package setup

## Documentation

For complete documentation, see:

- `docs/DRONE_FLIGHT_STACK_REAL.md` - Real hardware stack reference
- `docs/SIM_INTEGRATION_PLAN.md` - Simulation integration guide

## License

MIT
