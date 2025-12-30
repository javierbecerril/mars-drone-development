# ~/harmonic_ws/run_sitl_gazebo.sh
#!/usr/bin/env bash

source setup_harmonic_env.sh/bin/activate
source drone-venv/bin/activate


cd ~/harmonic_ws/src/ardupilot/Tools/autotest || exit 1

./sim_vehicle.py \
  -v ArduCopter \
  -f gazebo-iris \
  --model JSON \
  --console \
  --map
