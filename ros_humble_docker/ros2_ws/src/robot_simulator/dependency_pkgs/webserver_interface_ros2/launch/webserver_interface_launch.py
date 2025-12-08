from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='webserver_interface_ros2',
            executable='ros_handler',
            name='ros_handler',
            output='screen'
        ),
        Node(
            package='webserver_interface_ros2',
            executable='server',
            name='server',
            output='screen'
        ),
    ])