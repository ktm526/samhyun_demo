#!/bin/bash

# get container id
CONTAINER_ID=$(docker ps -q --filter ancestor=ros_humble_docker_ros2-dev)

if [ -z "$CONTAINER_ID" ]; then
  echo "ros2_devel 컨테이너가 실행 중이지 않거나 존재하지 않습니다."
  exit 1
fi

# connect container
docker exec -it $CONTAINER_ID bash
