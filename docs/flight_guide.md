# Flight Guide (harmonic_ws)

Date: 2025-12-20  
Stack: ArduPilot SITL + MAVROS + Gazebo Harmonic

## Pre-flight checklist (sim)
- `GZ_SIM_RESOURCE_PATH` includes local models: `$HOME/harmonic_ws/src/ardupilot_gazebo/models:$HOME/harmonic_ws/src/tag_hover_sim/models` (and install equivalents).
- ArduPilot SITL running (e.g., `--out 127.0.0.1:14550` and `--out 127.0.0.1:14555`).
- MAVROS launched (single instance) with matching `fcu_url`.
- Gazebo world loaded (e.g., `src/tag_hover_sim/worlds/apriltag_test.sdf`).
- Bridge + AprilTag nodes running (if testing lockon).

## Launch sequence (single UAV, lockon sim)
1) Start SITL:
```bash
cd ~/ardupilot && source venv/bin/activate
sim_vehicle.py -v ArduCopter -f gazebo-iris --console --map --out=127.0.0.1:14550 --out=127.0.0.1:14555
```
2) Start Gazebo:
```bash
cd ~/harmonic_ws
source /opt/ros/jazzy/setup.bash
source install/setup.bash
export GZ_SIM_RESOURCE_PATH=$GZ_SIM_RESOURCE_PATH:$HOME/harmonic_ws/src/ardupilot_gazebo/models:$HOME/harmonic_ws/src/tag_hover_sim/models
gz sim -r src/tag_hover_sim/worlds/apriltag_test.sdf
```
3) Start MAVROS (one instance):
```bash
ros2 launch mavros apm.launch fcu_url:=udp://:14555@127.0.0.1:14550
```
4) Start controller (if using lockon):
```bash
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py fcu_url:=udp://:14555@127.0.0.1:14550
```
5) Start camera bridge + apriltag_ros + PnP TF (see `LOCKON_NOTES.md` for exact commands).

## Verify connection
```bash
ros2 topic echo /mavros/state --once
```
Look for `connected: true`. Set mode (GUIDED/LOITER), arm, take off (via MAVProxy or a service call).

## Common warnings
- `AUTOPILOT_VERSION`/time jump warnings: typically benign; wait a few seconds after startup.
- Multiple MAVROS instances cause crashes; ensure only one per ROS domain (or use unique node names/namespaces).

## Troubleshooting quick checks
- No camera/detections: verify bridge topics and `apriltag_params.yaml` path; check `/camera/image_raw` hz.
- No TF tag frame: verify apriltag_ros publishes `/detections`, PnP broadcaster running.
- No yaw motion: ensure `/mavros/state` is connected and mode is GUIDED/LOITER; check `/hover_yaw_cmd`.

## Safe shutdown
- Disarm via MAVProxy (`disarm`) or MAVROS service if needed.
- Ctrl+C nodes; stop SITL last.
