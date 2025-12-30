# Code Index

This document maps the current `harmonic_ws` layout: packages, launch files, worlds, nodes, and key topics/parameters.  
Last updated: 2025-12-20.

## Workspace layout (relevant to this repo)
- `src/ardupilot_gazebo/` — Models/worlds for ArduPilot Gazebo integration (installed into `install/ardupilot_gazebo/...`).
- `src/tag_hover_sim/` — AprilTag hover/yaw-search simulation (Gazebo Harmonic + ArduPilot SITL).
- `LOCKON_NOTES.md` — Hands-on notes for the lockon/tag hover workflow.

## Packages

### tag_hover_sim
- `package.xml` — ROS 2 package manifest.
- `setup.py` — installs launch + config; registers console-scripts.
- `launch/`
  - `sim_lockon_backbone.launch.py` — Minimal bringup: MAVROS + `hover_yaw_search` (camera bridge, tag detector, and PnP TF run separately).
    - Args: `mode` (SEARCH/LOCK), `fcu_url` (e.g., `udp://:14555@127.0.0.1:14550` for ArduPilot SITL).
- `config/`
  - `apriltag_params.yaml` — AprilTag detector config (36h11, size 0.0376 m).
- `models/`
  - `iris_with_ardupilot`, `iris_with_rgb_camera` — Drone models (RGB variant has fixed gimbal).
  - `gimbal_small_3d_fixed` — Locked-joint gimbal used by the RGB model.
- `worlds/`
  - `apriltag_test.sdf`, `testing_nodrone.sdf` — Local test worlds.
- `tag_hover_sim/`
  - `hover_yaw_search.py` — Controller node (SEARCH yaw sweep; LOCK uses TF yaw error).
  - `apriltag_pnp_broadcaster.py`, `tag_overlay.py` — Helpers (TF, debug).
- Docs: `README.md`, `QUICK_REFERENCE.md`, `PACKAGE_SUMMARY.md`, plus repo-level `LOCKON_NOTES.md`.
- Key topics: `/camera/image_raw`, `/camera/camera_info`, `/detections`, `/tf` (camera -> tag36h11:0), `/mavros/state`, `/mavros/setpoint_velocity/cmd_vel_unstamped`, `/hover_yaw_cmd`.
- Modes: SEARCH (const yaw), LOCK (P yaw on tag).

### ardupilot_gazebo
- Provides models/worlds for ArduPilot + Gazebo (e.g., `iris_with_ardupilot`, `zephyr` variants, parachute, gimbal worlds).
- Installed share paths (after build): `install/ardupilot_gazebo/share/ardupilot_gazebo/models` and `.../worlds`.
- Use `GZ_SIM_RESOURCE_PATH` to point to these when launching Gazebo.

## Quick topic graph (tag hover focus)
- Camera: `/camera/image_raw`, `/camera/camera_info` (bridged from Gazebo).
- Detection: `/detections` (from `apriltag_ros`), TF `camera -> tag36h11:0`.
- Control: `/hover_yaw_cmd` (debug), `/mavros/setpoint_velocity/cmd_vel_unstamped` (to FCU).
- State: `/mavros/state` (connection/mode), `/mavros/local_position/...` (if needed).

## Paths and env hints
- Workspace root: `~/harmonic_ws`
- Source/setup:
  ```bash
  source /opt/ros/jazzy/setup.bash
  source ~/harmonic_ws/install/setup.bash
  ```
- Models in source:
  ```bash
  export GZ_SIM_RESOURCE_PATH=$GZ_SIM_RESOURCE_PATH:$HOME/harmonic_ws/src/ardupilot_gazebo/models:$HOME/harmonic_ws/src/tag_hover_sim/models
  ```
- Models in install:
  ```bash
  export GZ_SIM_RESOURCE_PATH=$GZ_SIM_RESOURCE_PATH:$HOME/harmonic_ws/install/ardupilot_gazebo/share/ardupilot_gazebo/models:$HOME/harmonic_ws/install/ardupilot_gazebo/share/ardupilot_gazebo/worlds
  ```

## Reminders
- Only one MAVROS per ROS domain; if starting separately, use unique `__node`/`namespace` or disable the one in `sim_lockon_backbone.launch.py`.
- ArduPilot SITL common ports: out 14550, listen 14555 (adjust if different).
- `/mission/new_target` (PointStamped) → follower_offboard_node
- `/uav2/mavros/setpoint_position/local` (PoseStamped) → MAVROS → PX4
- `/uav2/mavros/state` (State) ← MAVROS ← PX4
- Cameras via ros_gz_bridge:
  - `/uav1/camera/image_raw`, `/uav2/camera/image_raw` (+ camera_info)
  - Perception publishes `/uavX/perception/target`

## Running
1) Build and source:
- `cd ~/harmonic_ws` → `colcon build --symlink-install` → `source install/setup.bash`
2) Bringup (Harmonic): prefer `bringup_with_cameras.launch.py` (verify gz version aligns with Harmonic)
3) Start MAVROS (if not started by combined launch): `mavros_two_uav.launch.py`
4) Start mission: `demo_mission.launch.py`

## Known gaps / next steps
- All docs now aligned to Gazebo Harmonic (LTS). Garden references removed.
- Harden MAVROS bringup with a wait-for-port utility instead of fixed sleep (already present in `bringup_with_cameras.launch.py`)
- Optionally add compressed image transport and evaluate TFLite/ONNX for perception
