# Simulation Quick Reference

## Terminal Layout (3 terminals)

### Terminal 1: Gazebo Harmonic
```bash
gz sim drone_apriltag_world.sdf
```

### Terminal 2: ArduPilot SITL
```bash
cd ~/ardupilot/ArduCopter
../Tools/autotest/sim_vehicle.py -v ArduCopter -f gazebo-iris --console --map
```

Once SITL is ready, arm and takeoff:
```
mode GUIDED
arm throttle
takeoff 2
```

### Terminal 3: ROS 2 Stack
```bash
source /opt/ros/jazzy/setup.bash
source ~/harmonic_ws/install/setup.bash

# SEARCH mode (default)
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py

# LOCK mode
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py mode:=LOCK
```

## Runtime Commands

### Switch controller mode (Terminal 4)
```bash
# Switch to LOCK mode
ros2 param set /hover_yaw_search mode LOCK

# Switch back to SEARCH mode
ros2 param set /hover_yaw_search mode SEARCH
```

### Check topics
```bash
ros2 topic list
ros2 topic hz /image_raw
ros2 topic echo /detections
ros2 topic echo /mavros/state
ros2 topic echo /hover_yaw_cmd
```

### Check TF
```bash
# See all TF frames
ros2 run tf2_tools view_frames

# Monitor camera → tag transform
ros2 run tf2_ros tf2_echo camera tag36h11:0
```

### Visualize in RViz
```bash
rviz2
# Add TF display, set fixed frame to 'camera'
```
## Terminal Layout (matches real hardware workflow)
- Controller publishes constant yaw rate: `angular.z ≈ 0.25 rad/s`
### Terminal 1: Gazebo Harmonic (SIM ONLY - replaces physical drone)
```bash
gz sim drone_apriltag_world.sdf
```
- Drone rotates continuously looking for tag
### Terminal 2: Camera Bridge (SIM ONLY - replaces Intel RealSense D455 v4l2 camera node)
```bash
source ~/harmonic_ws/install/setup.bash
# CRITICAL: Gazebo SDF camera MUST be 1280×720 @ 30 FPS to match hardware
ros2 run ros_gz_bridge parameter_bridge /camera@sensor_msgs/msg/Image@gz.msgs.Image \
  --ros-args -r /camera:=/image_raw
ros2 run ros_gz_bridge parameter_bridge /camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo
```
- No dependency on TF
### Terminal 3: AprilTag Detector (IDENTICAL to real hardware)
```bash
source ~/harmonic_ws/install/setup.bash
ros2 run apriltag_ros apriltag_node \
	--ros-args -p image_rect:=/image_raw -p camera_info:=/camera_info \
	--params-file ~/harmonic_ws/src/tag_hover_sim/config/apriltag_params.yaml
```

### Terminal 4: PnP TF Broadcaster (IDENTICAL to real hardware)
```bash
python3 ~/apriltag_pnp_broadcaster.py
# Or wherever your PnP broadcaster script is located
```
### LOCK Mode
### Terminal 5: ArduPilot SITL (SIM ONLY - replaces Pixhawk)
```bash
cd ~/ardupilot/ArduCopter
../Tools/autotest/sim_vehicle.py -v ArduCopter -f gazebo-iris --console --map
```
- Controller computes yaw error from TF `camera → tag36h11:0`
Once SITL is ready, arm and takeoff:
```
mode GUIDED
arm throttle
takeoff 2
```
- Yaw error = `atan2(tag_x, tag_z)` (angular offset in camera frame)
### Terminal 6: MAVROS + Controller (IDENTICAL structure to real hardware)
```bash
source ~/harmonic_ws/install/setup.bash
- Controller applies P gain: `yaw_cmd = lock_k_yaw * yaw_error`
# SEARCH mode (default)
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py
- Drone adjusts yaw to center tag (yaw error → 0)
# LOCK mode
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py mode:=LOCK
```
- Falls back to SEARCH if TF is unavailable

## Troubleshooting One-Liners

```bash
# Is Gazebo camera publishing?
ros2 topic hz /image_raw

# Is AprilTag detector running?
ros2 node list | grep apriltag

# Is MAVROS connected?
ros2 topic echo /mavros/state | grep connected

# Is TF available?
ros2 run tf2_ros tf2_echo camera tag36h11:0

# What's the controller commanding?
ros2 topic echo /mavros/setpoint_velocity/cmd_vel_unstamped

# SITL listening on UDP?
netstat -an | grep 14540
```

## Shutdown Sequence

1. Ctrl+C in Terminal 3 (ROS 2 stack)
2. In Terminal 2 MAVProxy: `disarm` → `exit`
3. Close Gazebo (Terminal 1)
