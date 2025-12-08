#!/bin/bash

# Delete all files and directories in src/ of each C++ package
for pkg in amr_core amr_odometry amr_navigation amr_interface; do
  SRC_DIR="dependency_pkgs/MOBILE_ROBOT_BASIC/$pkg/src"
  if [ -d "$SRC_DIR" ]; then
    echo "Deleting all files and directories in $SRC_DIR"
    rm -rf "$SRC_DIR"/*
  fi
done

# Delete only waypoint_node_manager named .c, .py, .pyx files
WPM_DIR="dependency_pkgs/waypoint_node_manager/waypoint_node_manager/waypoint_node_manager"
if [ -d "$WPM_DIR" ]; then
  echo "Deleting waypoint_node_manager .c, .py, .pyx files in $WPM_DIR"
  rm -f "$WPM_DIR"/waypoint_node_manager.c "$WPM_DIR"/waypoint_node_manager.py "$WPM_DIR"/waypoint_node_manager.pyx
fi


# Delete only webserver_interface_manager named .c, .pyx files
WSI_DIR="dependency_pkgs/webserver_interface_ros2/webserver_interface_ros2"
if [ -d "$WSI_DIR" ]; then
  echo "Deleting webserver_interface_ros2 .c, .py, .pyx files in $WPM_DIR"
  rm -f "$WSI_DIR"/ros_handler_.pyx "$WSI_DIR"/ros_handler_.c "$WSI_DIR"/node_manager_.pyx "$WSI_DIR"/node_manager_.c "$WSI_DIR"/server_.c "$WSI_DIR"/server_.pyx "$WSI_DIR"/vda5050_manager_.c "$WSI_DIR"/vda5050_manager_.pyx
fi

echo "Source files deleted." 
