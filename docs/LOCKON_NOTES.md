# Simulation + Lockon Integration Notes

## Worlds and Models
- `src/tag_hover_sim/worlds/apriltag_test.sdf` includes `model://iris_with_ardupilot` (patched with fully scoped names) and an AprilTag board.
- `src/tag_hover_sim/models/iris_with_ardupilot` includes `iris_with_standoffs` and references links/joints as `iris_with_ardupilot::iris_with_standoffs::rotor_*` plus the IMU.
- `src/tag_hover_sim/models/iris_with_rgb_camera` adds a fixed gimbal by including `gimbal_small_3d_fixed`, attaching it via `gimbal_mount` to the base, and orienting it forward.

## Gimbal Fix
- Cloned `gimbal_small_3d` to `gimbal_small_3d_fixed`, updated mesh URIs, and locked yaw/roll/pitch joint limits to 0 so it does not drift.
- Included `gimbal_small_3d_fixed` in `iris_with_rgb_camera`, fixed joint to the mount, and adjusted pose to face forward.

## Resource Paths
- Ensure `GZ_SIM_RESOURCE_PATH` includes the model roots when launching Gazebo: `src/ardupilot_gazebo/models` and `src/tag_hover_sim/models`.

## AprilTag + Camera
- Bridge the Gazebo camera to ROS 2 using `ros_gz_bridge` (parameter_bridge), remapping the Gazebo topics to `/camera/image_raw` and `/camera/camera_info`.
- Run `apriltag_ros` with `src/tag_hover_sim/config/apriltag_params.yaml`, remapping `image` and `camera_info` to the bridged topics.

## Controller (`hover_yaw_search`)
- Subscribes to `/mavros/state` and TF `camera -> tag`.
- Publishes yaw rate to `/mavros/setpoint_velocity/cmd_vel_unstamped` (and `/hover_yaw_cmd` for debug).
- Modes:
  - SEARCH: constant `search_yaw` (default 0.25 rad/s).
  - LOCK: uses TF yaw error; falls back to `search_yaw` if TF is missing.
- Requires MAVROS connected and FCU mode GUIDED/LOITER/GUIDED_NOGPS.

## MAVROS Launch
- `src/tag_hover_sim/launch/sim_lockon_backbone.launch.py` starts both MAVROS (`mavros_node`) and `hover_yaw_search`.
- Avoid running a second MAVROS in the same ROS domain. If you need to, give it a unique `__node` and `namespace`, or disable MAVROS in the launch.
- Typical ArduPilot SITL ports: listen 14555, send 14550; use `fcu_url:=udp://:14555@127.0.0.1:14550` (adjust to your setup).

## Common Issues
- MAVROS crash “existing topic name … incompatible type”: happens if multiple MAVROS instances share the same name/namespace/domain. Kill stale `mavros_node` and relaunch with unique name/ns or a fresh ROS domain.
- Time jump warnings: benign; set `use_sim_time:=true` if using `/clock`.

## Launch Sequence (working)
1) Start SITL (set `--out` ports, e.g., 14550/14555).
2) Launch `sim_lockon_backbone.launch.py` with correct `fcu_url` (and unique MAVROS name/ns if needed).
3) Start the camera bridge to `/camera/image_raw` + `/camera/camera_info`.
4) Run `apriltag_ros` with `apriltag_params.yaml`.
5) Verify `/mavros/state` is connected; arm and set GUIDED/LOITER; SEARCH mode will rotate until a tag is seen.
