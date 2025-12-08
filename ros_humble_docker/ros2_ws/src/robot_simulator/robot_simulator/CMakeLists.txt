cmake_minimum_required(VERSION 3.5)

project(robot_simulator)

find_package(ament_cmake REQUIRED)

install(DIRECTORY launch param rviz worlds maps robots
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()