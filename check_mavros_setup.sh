#!/bin/bash
# Diagnostic script to verify MAVROS + ArduPilot SITL connection setup

set -e

echo "========== MAVROS + ArduPilot SITL Diagnostic =========="
echo ""

# Check 1: Is ArduPilot SITL running?
echo "[1] Checking if ArduPilot SITL is running..."
if netstat -tlnp 2>/dev/null | grep -E ':(14550|14555)' > /dev/null; then
    echo "    ✓ Found listeners on ports 14550 or 14555"
    netstat -tlnp 2>/dev/null | grep -E ':(14550|14555)'
else
    echo "    ✗ No listener on 14550/14555. ArduPilot SITL may not be running!"
    echo "    Start ArduPilot SITL first. Expected: sim_vehicle.py --out 127.0.0.1:14550"
fi
echo ""

# Check 2: ROS nodes running?
echo "[2] Checking ROS 2 nodes..."
source /opt/ros/jazzy/setup.bash
ROS_NODES=$(ros2 node list 2>/dev/null || echo "")
if echo "$ROS_NODES" | grep -q mavros; then
    echo "    ✓ /mavros node found"
else
    echo "    ✗ /mavros node NOT running"
fi

if echo "$ROS_NODES" | grep -q hover_yaw_search; then
    echo "    ✓ /hover_yaw_search node found"
else
    echo "    ✗ /hover_yaw_search node NOT running"
fi
echo ""

# Check 3: MAVROS state topic
echo "[3] Checking MAVROS /state topic..."
if ros2 topic list 2>/dev/null | grep -q "/mavros/state"; then
    echo "    ✓ /mavros/state topic exists"
    echo "    Attempting to read state..."
    timeout 2 ros2 topic echo /mavros/state --once 2>/dev/null | head -5 || echo "    (timeout or no data)"
else
    echo "    ✗ /mavros/state topic NOT found"
fi
echo ""

# Check 4: Parameter check
echo "[4] Checking MAVROS parameters..."
if ros2 param get /mavros fcu_url 2>/dev/null; then
    echo "    ✓ fcu_url parameter set"
else
    echo "    ✗ Could not read fcu_url parameter"
fi
echo ""

echo "========== Diagnostic Complete =========="
