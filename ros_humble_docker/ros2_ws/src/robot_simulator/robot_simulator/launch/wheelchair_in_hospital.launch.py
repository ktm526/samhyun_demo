#!/usr/bin/env python3

from os.path import join
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, AppendEnvironmentVariable
from launch.substitutions import LaunchConfiguration, Command, PythonExpression
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    pkg_path = get_package_share_directory('robot_simulator')
    gz_sim_share = get_package_share_directory('ros_gz_sim')

    # Path to original wheelchair xacro
    xacro_path = join(pkg_path, 'robots/wheelchair/urdf/wheelchair.xacro')

    # Launch arguments for initial pose
    position_x = LaunchConfiguration('position_x')
    position_y = LaunchConfiguration('position_y')
    position_z = LaunchConfiguration('position_z')
    orientation_yaw = LaunchConfiguration('orientation_yaw')
    world_file = LaunchConfiguration('world_file')

    # Include Ignition Gazebo simulator
    gz_sim = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(join(gz_sim_share, "launch", "gz_sim.launch.py")),
        launch_arguments={
            "gz_args": PythonExpression(["'", world_file, " -r'"]),
        }.items()
    )

    # Robot State Publisher with xacro processed description
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='wheelchair_state_publisher',
        parameters=[{'robot_description': Command(['xacro', ' ', xacro_path, 
                                                    ' sim_ign:=true', 
                                                    ' lidar_enabled:=true', 
                                                    ' camera_enabled:=true', 
                                                    ' imu_enabled:=true',
                                                    ' odom_publish_frequency:=30',
                                                    ' cmd_vel_topic:=/cmd_vel',
                                                    ' odom_frame_id:=odom',
                                                    ' base_footprint_frame_id:=base_footprint'])}]
    )

    # Spawn entity in Ignition Gazebo using the description published above
    spawn_entity = Node(
        package='ros_gz_sim',
        executable='create',
        arguments=[
            '-topic', '/robot_description',
            '-name', 'wheelchair',
            '-allow_renaming', 'true',
            '-x', position_x,
            '-y', position_y,
            '-z', position_z,
            '-Y', orientation_yaw
        ]
    )

    # Bridge commonly used topics between ROS 2 and Ignition
    gz_ros2_bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        arguments=[
            '/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist',
            '/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock',
            '/odom@nav_msgs/msg/Odometry[ignition.msgs.Odometry',
            '/tf@tf2_msgs/msg/TFMessage[ignition.msgs.Pose_V',
            '/scan_right@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',
            '/scan_left@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan',
            '/imu@sensor_msgs/msg/Imu[ignition.msgs.IMU',
            # Camera bridges
            '/camera_right/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image',
            '/camera_right/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo',
            '/camera_left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image',
            '/camera_left/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo'
        ]
    )

    # Example static transform publisher (optional placeholder)
    transform_publisher = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        arguments=[
            '--x', '0.0', '--y', '0.0', '--z', '0.0',
            '--yaw', '0.0', '--pitch', '0.0', '--roll', '0.0',
            '--frame-id', 'map', '--child-frame-id', 'wheelchair/base_footprint'
        ]
    )

    return LaunchDescription([
        # Environment variables for Ignition Gazebo
        AppendEnvironmentVariable(
            name='IGN_GAZEBO_RESOURCE_PATH',
            value=join(pkg_path, "worlds")
        ),
        AppendEnvironmentVariable(
            name='IGN_GAZEBO_RESOURCE_PATH',
            value=join(pkg_path, "models")
        ),
        AppendEnvironmentVariable(
            name='IGN_RENDERING_ENGINE_PATH',
            value='/usr/lib/x86_64-linux-gnu/ign-rendering-6/engine-plugins'
        ),
        
        # Launch arguments
        DeclareLaunchArgument('position_x', default_value='-3.0'),
        DeclareLaunchArgument('position_y', default_value='8.0'),
        DeclareLaunchArgument('position_z', default_value='0.0'),
        DeclareLaunchArgument('orientation_yaw', default_value='0.0'),
        DeclareLaunchArgument('world_file', default_value=join(pkg_path, 'worlds', 'hospital', 'hospital.sdf')),

        # DeclareLaunchArgument('position_x', default_value='0.0'),
        # DeclareLaunchArgument('position_y', default_value='0.0'),
        # DeclareLaunchArgument('position_z', default_value='0.0'),
        # DeclareLaunchArgument('orientation_yaw', default_value='0.0'),
        # DeclareLaunchArgument('world_file', default_value=join(pkg_path, 'worlds', 'warehouse', 'warehouse.sdf')),
        
        # Launch components
        gz_sim,
        robot_state_publisher,
        spawn_entity,
        # transform_publisher,
        gz_ros2_bridge
    ]) 