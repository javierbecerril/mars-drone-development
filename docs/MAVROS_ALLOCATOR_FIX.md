# Note
This content was consolidated into docs/LOCKON_NOTES.md. Keeping this file as a stub to avoid new documents.

### 2. **ArduPilot SITL not sending MAVLink to MAVROS port**
- **Was:** `sim_vehicle.py` with no `--out` flag (defaults to FDM-only, no MAVLink on 14550)
- **Now:** `sim_vehicle.py ... --out=127.0.0.1:14550` (sends MAVLink to MAVROS)

**Why it matters:**  
- By default, ArduPilot SITL only sends FDM updates on UDP ports 9002/9003 (for Gazebo)
- MAVROS expects MAVLink protocol on port 14550
- Without `--out=127.0.0.1:14550`, MAVROS couldn't connect, causing the initialization crash

### 3. **Parameter mismatch in controller launch**
- **Was:** `search_yaw_rate`, `lock_kp`, `image_width` (wrong names)
- **Now:** `rate_hz`, `search_yaw`, `lock_k_yaw` (matches code)

**Why it matters:**  
The controller's `__init__` looks for specific parameter names. Mismatches could cause initialization issues.

---

## Changes Made

1. **`run_sitl_gazebo.sh`** — Added `--out=127.0.0.1:14550`
2. **`launch/sim_lockon_backbone.launch.py`** — Fixed `fcu_url` to `udp://:14555@127.0.0.1:14550` and corrected all parameter names
3. **`tag_hover_sim/hover_yaw_search.py`** — Improved MAVROS initialization handling with timeout and logging
4. **Created `check_mavros_setup.sh`** — Diagnostic script to verify connections

---

## Expected Behavior After Fix

1. **ArduPilot SITL starts** → sends FDM to Gazebo (9002/9003) AND MAVLink to MAVROS (14550)
2. **MAVROS launches** → connects to ArduPilot via UDP on port 14550
3. **Controller launches** → waits up to 10 seconds for MAVROS state, then begins control loop
4. **No more allocator errors**

---

## Quick Test Checklist

```bash
# 1. Run ArduPilot SITL
./run_sitl_gazebo.sh

# 2. In another terminal, check MAVROS is receiving data
netstat -tlnp | grep -E '14550|14555'
# Should show listeners on both ports

# 3. Source and launch Gazebo + controller
source install/setup.bash
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py

# 4. Verify in another terminal
ros2 topic echo /mavros/state --once
# Should see: connected: true, mode: GUIDED (or your set mode)

# 5. Check controller is healthy
ros2 topic hz /hover_yaw_cmd
# Should show ~20 Hz if running
```

---

## Port Reference

| Service        | Port    | Direction | Role                |
|---|---|---|---|
| ArduPilot FDM  | 9002    | In        | Gazebo → ArduPilot  |
| ArduPilot FDM  | 9003    | Out       | ArduPilot → Gazebo  |
| MAVROS Listen  | 14555   | In        | ArduPilot → MAVROS  |
| ArduPilot MAVLink | 14550 | Out       | ArduPilot → MAVROS  |

---

## Future: Hardware Deployment

On real hardware, the command would be:
```bash
ros2 launch tag_hover_sim sim_lockon_backbone.launch.py fcu_url:=serial:///dev/ttyAMA0:57600
```
(No `--out` needed; serial connection is direct.)
