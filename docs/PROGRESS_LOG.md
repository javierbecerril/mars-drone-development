# PROGRESS LOG

## 2026-01-08 (Continued)
**Summary:**
- Fixed environment setup: added `COLCON_IGNORE` to `drone-venv` to prevent colcon scanning errors.
- Installed wxPython in drone-venv to fix MAVProxy console/map GUI modules.
- Successfully launched Terminals 1-3 (SITL, Gazebo, Camera Bridge).
- **Key finding:** Simple camera bridge (`/camera/image_raw`) doesn't work; must use full scoped path with remapping (see below).
- Camera now publishing at ~6-7 Hz on `/camera/image_raw` and `/camera/camera_info`.

**MAVROS + Controller bringup (split works reliably):**
- Launched MAVROS standalone via `apm.launch`:
  ```bash
  ros2 launch mavros apm.launch fcu_url:=udp://:14555@127.0.0.1:14550
  ```
- Launched controller pointing to `/mavros`:
  ```bash
  ros2 run tag_hover_sim hover_yaw_search --ros-args -p mavros_prefix:=/mavros -p mode:=SEARCH
  ```
- Verified: controller logs show "MAVROS connected and ready"; SEARCH mode yaw spin observed.
- Verified log lines (controller):
  - `[INFO] [...] [hover_yaw_search]: Waiting for MAVROS initialization... (X.Xs/10.0s)`
  - `[INFO] [...] [hover_yaw_search]: MAVROS connected and ready`
  - `[WARN] [...] [hover_yaw_search]: FCU mode is LAND, expected GUIDED/GUIDED_NOGPS/LOITER for testing.`
- Set mode/arm/takeoff via services or MAVProxy:
  ```bash
  ros2 service call /mavros/set_mode mavros_msgs/srv/SetMode "{base_mode: 0, custom_mode: 'GUIDED'}"
  ros2 service call /mavros/cmd/arming mavros_msgs/srv/CommandBool "{value: true}"
  # Optional: CommandTOL or MAVProxy 'takeoff 5'
  ```

**Note on combined launch:**
- `sim_lockon_backbone.launch.py` can still launch MAVROS + controller together, but ensure unique names/prefixes to avoid duplicate-topic errors.

**Working Commands:**
- **Terminal 3 (Camera Bridge):** Use the scoped path with remapping (not simple bridge):
  ```bash
  ros2 run ros_gz_bridge parameter_bridge \
    /world/apriltag_test/model/iris_with_rgb_camera/model/gimbal/link/pitch_link/sensor/camera/image@sensor_msgs/msg/Image@gz.msgs.Image \
    /world/apriltag_test/model/iris_with_rgb_camera/model/gimbal/link/pitch_link/sensor/camera/camera_info@sensor_msgs/msg/CameraInfo@gz.msgs.CameraInfo \
    --ros-args \
    -r /world/apriltag_test/model/iris_with_rgb_camera/model/gimbal/link/pitch_link/sensor/camera/image:=/camera/image_raw \
    -r /world/apriltag_test/model/iris_with_rgb_camera/model/gimbal/link/pitch_link/sensor/camera/camera_info:=/camera/camera_info
  ```

**Next Todos:**
- [ ] Launch Terminal 4 (MAVROS + Controller) and verify `/mavros/state` shows `connected: true`.
- [ ] Launch Terminal 5 (AprilTag Detector).
- [ ] Launch Terminal 6 (AprilTag TF Broadcaster).
- [ ] Launch Terminal 7 (AprilTag PnP Broadcaster).
- [ ] Verify full system integration and test arm/takeoff/SEARCH→LOCK modes.
 - [ ] Tune `lock_k_yaw` and `search_yaw` as needed.

---

## 2026-01-07
**Summary:**
- Reviewed project status and documentation baseline (ALL_WORK_SUMMARY.md, LOCKON_NOTES.md).
- Set up PROGRESS_LOG.md as working session tracker with date stamps and next todos.
- Created STARTUP_CHECKLIST.md with environment sourcing reference.
- Established THESIS_SYNC_AGENT.md purpose (thesis-relevant insights only).

**Issues Resolved:**
- Fixed `ardupilot_sitl` build failure by adding `COLCON_IGNORE` to drone-venv.
- Clarified sourcing strategy: use `setup_harmonic_env.sh` for ROS 2 + Gazebo, use `drone-venv` for ArduPilot SITL.
- Harmless warning: `ardupilot_sitl` package missing `local_setup.bash` (can skip this package in future builds).
