#!/usr/bin/env python3
"""
Simulation backbone launch file — minimal parity with real hardware lockon_backbone.launch.py

Real hardware launches only MAVROS (serial) and hover_yaw_search; camera, detector,
and TF broadcaster run separately. Simulation mirrors that workflow, launching only
MAVROS (UDP to SITL) and the controller here.
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
  fcu_url_arg = DeclareLaunchArgument(
    'fcu_url',
    #default_value='udp://:14540@127.0.0.1:14550', #This section is different from hardware because serial is hardware only, udp is simulation only
    default_value='udp://127.0.0.1:14550@',
    description='MAVROS FCU URL (sim: UDP to SITL; real: serial:///dev/ttyAMA0:57600)'
  )

  mode_arg = DeclareLaunchArgument(
    'mode',
    default_value='SEARCH',
    description='Controller mode: SEARCH or LOCK'
  )

  mavros_node = Node(
    package='mavros',
    executable='mavros_node',
    name='mavros',
    output='screen',
    parameters=[
      {'fcu_url': LaunchConfiguration('fcu_url')},
      {'use_sim_time': True}
    ]
  )

  hover_yaw_search_node = Node(
    #package='tag_hover_controller',
    package='tag_hover_sim',
    executable='hover_yaw_search',
    name='hover_yaw_search',
    output='screen',
    parameters=[
      {'mode': LaunchConfiguration('mode')},
      {'rate_hz': 20.0},                   # control loop rate
      {'search_yaw': 0.25},                # spin speed in SEARCH mode (rad/s)
      {'lock_k_yaw': 0.0025},              # P gain for yaw lock
      {'camera_frame': 'camera'},          # camera frame name
      {'tag_frame': 'tag36h11:0'},         # tag frame name
      {'max_yaw_rate': 0.6},               # max yaw rate (rad/s)
      {'mavros_wait_timeout': 10.0},       # wait up to 10s for MAVROS
      {'use_sim_time': True}
    ]
  )

  return LaunchDescription([
    fcu_url_arg,
    mode_arg,
    mavros_node,
    hover_yaw_search_node,
  ])
