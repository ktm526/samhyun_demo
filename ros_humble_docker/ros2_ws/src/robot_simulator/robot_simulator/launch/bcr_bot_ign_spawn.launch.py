#!/usr/bin/python3

from os.path import join
from xacro import parse, process_doc

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, Command

from launch_ros.actions import Node

from ament_index_python.packages import get_package_share_directory

def get_xacro_to_doc(xacro_file_path, mappings):
    doc = parse(open(xacro_file_path))
    process_doc(doc, mappings=mappings)
    return doc

def generate_launch_description():
   
    bcr_bot_path = get_package_share_directory("robot_simulator")
    position_x = LaunchConfiguration("position_x")
    position_y = LaunchConfiguration("position_y")
    orientation_yaw = LaunchConfiguration("orientation_yaw")

    front_kinect_camera_enabled = LaunchConfiguration("front_kinect_camera_enabled", default=True)
    front_stereo_camera_enabled = LaunchConfiguration("front_stereo_camera_enabled", default=True)

    back_kinect_camera_enabled = LaunchConfiguration("back_kinect_camera_enabled", default=True)
    back_stereo_camera_enabled = LaunchConfiguration("back_stereo_camera_enabled", default=True)

    left_kinect_camera_enabled = LaunchConfiguration("left_kinect_camera_enabled", default=True)
    left_stereo_camera_enabled = LaunchConfiguration("left_stereo_camera_enabled", default=True)

    right_kinect_camera_enabled = LaunchConfiguration("right_kinect_camera_enabled", default=True)
    right_stereo_camera_enabled = LaunchConfiguration("right_stereo_camera_enabled", default=True)

    two_d_lidar_enabled = LaunchConfiguration("two_d_lidar_enabled", default=True)
    odometry_source = LaunchConfiguration("odometry_source")

    # robot_description_content = get_xacro_to_doc(
    #     join(bcr_bot_path, "urdf", "bcr_bot.xacro"),
    #     {"sim_gz": "true",
    #      "two_d_lidar_enabled": "true",
    #      "conveyor_enabled": "false",
    #      "camera_enabled": "true"
    #     }
    # ).toxml()

    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        name="robot_state_publisher",
        parameters=[
                    {'robot_description': Command( \
                    ['xacro ', join(bcr_bot_path, 'robots/hamr/urdf/bcr_bot.xacro'),
                    ' front_kinect_camera_enabled:=', front_kinect_camera_enabled,
                    ' front_stereo_camera_enabled:=', front_stereo_camera_enabled,
                    ' back_kinect_camera_enabled:=', back_kinect_camera_enabled,
                    ' back_stereo_camera_enabled:=', back_stereo_camera_enabled,
                    ' left_kinect_camera_enabled:=', left_kinect_camera_enabled,
                    ' left_stereo_camera_enabled:=', left_stereo_camera_enabled,
                    ' right_kinect_camera_enabled:=', right_kinect_camera_enabled,
                    ' right_stereo_camera_enabled:=', right_stereo_camera_enabled,                        
                    ' two_d_lidar_enabled:=', two_d_lidar_enabled,
                    ' odometry_source:=', odometry_source,
                    ' sim_ign:=', "true"
                    ])}],
        # remappings=[
        #     ('/joint_states', 'bcr_bot/joint_states'),
        # ]
    )

    gz_spawn_entity = Node(
        package="ros_gz_sim",
        executable="create",
        arguments=[
            "-topic", "/robot_description",
            "-name", "bcr_bot",
            "-allow_renaming", "true",
            "-z", "0.28",
            "-x", position_x,
            "-y", position_y,
            "-Y", orientation_yaw
        ]
    )

    gz_ros2_bridge = Node(
        package="ros_gz_bridge",
        executable="parameter_bridge",
        arguments=[
            "/cmd_vel@geometry_msgs/msg/Twist@ignition.msgs.Twist",
            "/clock@rosgraph_msgs/msg/Clock[ignition.msgs.Clock",
            "/odom@nav_msgs/msg/Odometry[ignition.msgs.Odometry",
            "/tf@tf2_msgs/msg/TFMessage[ignition.msgs.Pose_V",
            "/scan@sensor_msgs/msg/LaserScan[ignition.msgs.LaserScan",
            
            "/front_kinect_camera@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            # "/front_stereo_camera/left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            "/front_stereo_camera/left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            "/front_stereo_camera/right/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            # "/front_kinect_camera/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            "/front_stereo_camera/left/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            "/front_stereo_camera/right/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            # "/front_kinect_camera/points@sensor_msgs/msg/PointCloud2[ignition.msgs.PointCloudPacked",
            
            "/back_kinect_camera@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            "/back_stereo_camera/left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            "/back_stereo_camera/right/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            # "/back_kinect_camera/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            "/back_stereo_camera/left/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            "/back_stereo_camera/right/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            # "/back_kinect_camera/points@sensor_msgs/msg/PointCloud2[ignition.msgs.PointCloudPacked",

            "/left_kinect_camera@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            "/left_stereo_camera/left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            "/left_stereo_camera/right/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            # "/left_kinect_camera/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            "/left_stereo_camera/left/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            "/left_stereo_camera/right/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            # "/left_kinect_camera/points@sensor_msgs/msg/PointCloud2[ignition.msgs.PointCloudPacked",

            "/right_kinect_camera@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            "/right_stereo_camera/left/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            "/right_stereo_camera/right/image_raw@sensor_msgs/msg/Image[ignition.msgs.Image",
            
            # "/right_kinect_camera/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            "/right_stereo_camera/left/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            "/right_stereo_camera/right/camera_info@sensor_msgs/msg/CameraInfo[ignition.msgs.CameraInfo",
            
            # "/right_kinect_camera/points@sensor_msgs/msg/PointCloud2[ignition.msgs.PointCloudPacked",

            "/imu@sensor_msgs/msg/Imu[ignition.msgs.IMU",

            "/world/default/model/bcr_bot/joint_state@sensor_msgs/msg/JointState[ignition.msgs.Model"
        ],
        remappings=[
            ('/front_stereo_camera/left/image_raw', 'camera_image_front'),
            ('/back_stereo_camera/left/image_raw', 'camera_image_rear'),
            ('/left_stereo_camera/left/image_raw', 'camera_image_left'),
            ('/right_stereo_camera/left/image_raw', 'camera_image_right'),
        ]
    )

    # transform_publisher = Node(
    #     package="tf2_ros",
    #     executable="static_transform_publisher",
    #     arguments = ["--x", "0.0",
    #                 "--y", "0.0",
    #                 "--z", "0.0",
    #                 "--yaw", "0.0",
    #                 "--pitch", "0.0",
    #                 "--roll", "0.0",
    #                 "--frame-id", "kinect_camera",
    #                 "--child-frame-id", "bcr_bot/base_footprint/kinect_camera"]
    # )

    transform_publisher = Node(
        package="tf2_ros",
        executable="static_transform_publisher",
        arguments = ["--x", "0.0",
                    "--y", "0.0",
                    "--z", "0.0",
                    "--yaw", "0.0",
                    "--pitch", "0.0",
                    "--roll", "0.0",
                    "--frame-id", "map",
                    "--child-frame-id", "base_link"]
    )

    return LaunchDescription([
        DeclareLaunchArgument("front_kinect_camera_enabled", default_value = front_kinect_camera_enabled),
        DeclareLaunchArgument("front_stereo_camera_enabled", default_value = front_stereo_camera_enabled),

        DeclareLaunchArgument("back_kinect_camera_enabled", default_value = back_kinect_camera_enabled),
        DeclareLaunchArgument("back_stereo_camera_enabled", default_value = back_stereo_camera_enabled),

        DeclareLaunchArgument("left_kinect_camera_enabled", default_value = left_kinect_camera_enabled),
        DeclareLaunchArgument("left_stereo_camera_enabled", default_value = left_stereo_camera_enabled),

        DeclareLaunchArgument("right_kinect_camera_enabled", default_value = right_kinect_camera_enabled),
        DeclareLaunchArgument("right_stereo_camera_enabled", default_value = right_stereo_camera_enabled),

        DeclareLaunchArgument("two_d_lidar_enabled", default_value = two_d_lidar_enabled),
        DeclareLaunchArgument("position_x", default_value="12.16"),
        DeclareLaunchArgument("position_y", default_value="-10.84"),
        DeclareLaunchArgument("orientation_yaw", default_value="1.5707963267948966"),
        DeclareLaunchArgument("odometry_source", default_value="world"),
        robot_state_publisher,
        gz_spawn_entity, transform_publisher, gz_ros2_bridge
    ])