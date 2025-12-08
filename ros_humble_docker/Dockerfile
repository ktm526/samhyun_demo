# Base Image: ROS2 Humble Desktop Full
FROM osrf/ros:humble-desktop-full-jammy

ENV DEBIAN_FRONTEND=noninteractive

# # Disable APT caching to avoid hash sum mismatch
# RUN echo 'Acquire::http::No-Cache "true";' > /etc/apt/apt.conf.d/99no-cache

RUN sed -i 's|http://archive.ubuntu.com/ubuntu|http://mirror.kakao.com/ubuntu|g' /etc/apt/sources.list && \
    sed -i 's|http://security.ubuntu.com/ubuntu|http://mirror.kakao.com/ubuntu|g' /etc/apt/sources.list

# Locale Setting
RUN apt-get clean && rm -rf /var/lib/apt/lists/* && apt-get update && apt-get install -y locales && \
    locale-gen en_US en_US.UTF-8 && \
    update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8

# Clean old ROS 2 key & source, install curl & certs
RUN rm -f /etc/apt/sources.list.d/ros2-latest.list && \
    rm -f /usr/share/keyrings/ros2-latest-archive-keyring.gpg && \
    apt-get clean && rm -rf /var/lib/apt/lists/* && apt-get update && \
    apt-get install -y ca-certificates curl gnupg2 lsb-release

# Install latest ros-apt-source from GitHub (dynamic version)
RUN export ROS_APT_SOURCE_VERSION=$(curl -s https://api.github.com/repos/ros-infrastructure/ros-apt-source/releases/latest | grep -F "tag_name" | awk -F\" '{print $4}') && \
    curl -L -s -o /tmp/ros2-apt-source.deb "https://github.com/ros-infrastructure/ros-apt-source/releases/download/${ROS_APT_SOURCE_VERSION}/ros2-apt-source_${ROS_APT_SOURCE_VERSION}.$(. /etc/os-release && echo $VERSION_CODENAME)_all.deb" && \
    apt-get update && apt-get install -y /tmp/ros2-apt-source.deb && \
    rm -f /tmp/ros2-apt-source.deb

# Additional Package Install (ROS2 is already installed)
RUN apt-get update && apt-get install -y --no-install-recommends \
    bash-completion \
    curl \
    gnupg2 \
    lsb-release \
    vim \
    net-tools \
    iputils-ping \
    gedit \
    python3-pip \
    git \
    software-properties-common \
    wget \
    sudo \
    unzip \
    python3-colcon-common-extensions \
    ros-humble-can-msgs \
    libmodbus-dev \
    && rm -rf /var/lib/apt/lists/*

# Gazebo Fortress Install
RUN apt-get update && apt-get install -y \
    wget \
    gnupg \
    lsb-release && \
    wget https://packages.osrfoundation.org/gazebo.gpg -O /usr/share/keyrings/pkgs-osrf-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/pkgs-osrf-archive-keyring.gpg] http://packages.osrfoundation.org/gazebo/ubuntu-stable $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/gazebo-stable.list > /dev/null

RUN apt-get clean && rm -rf /var/lib/apt/lists/* && apt-get update && apt-get install -y \
    gz-fortress && rm -rf /var/lib/apt/lists/*

# Bash completion setting
RUN sed -i 's/^#if ! shopt -oq posix; then/if ! shopt -oq posix; then/' /etc/bash.bashrc && \
    sed -i 's/^# *if \[ -f \/usr\/share\/bash-completion\/bash_completion \]; then/  if [ -f \/usr\/share\/bash-completion\/bash_completion ]; then/' /etc/bash.bashrc && \
    sed -i 's/^# *\. \/usr\/share\/bash-completion\/bash_completion/    . \/usr\/share\/bash-completion\/bash_completion/' /etc/bash.bashrc && \
    sed -i 's/^# *elif \[ -f \/etc\/bash_completion \]; then/  elif [ -f \/etc\/bash_completion ]; then/' /etc/bash.bashrc && \
    sed -i 's/^# *\. \/etc\/bash_completion/    . \/etc\/bash_completion/' /etc/bash.bashrc && \
    sed -i 's/^#  fi/  fi/' /etc/bash.bashrc && \
    sed -i 's/^#fi/fi/' /etc/bash.bashrc

# ROS 2 environment setting
RUN echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc &&\
    echo "source ~/ros2_ws/install/setup.sh" >> ~/.bashrc &&\
    echo "source /usr/share/gazebo/setup.sh" >> ~/.bashrc &&\
    echo "alias sb='source ~/.bashrc'" >> ~/.bashrc &&\
    echo "alias sds='source ~/ros2_ws/install/setup.bash'" >> ~/.bashrc &&\
    echo "alias cw='cd ~/ros2_ws'" >> ~/.bashrc &&\
    echo "alias cs='cd ~/ros2_ws/src'" >> ~/.bashrc &&\
    echo "alias cm='cd ~/ros2_ws && colcon build --symlink-install'" >> ~/.bashrc &&\
    echo "export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp" >> ~/.bashrc &&\
    echo "export ROS_DOMAIN_ID=59" >> ~/.bashrc

# Gazebo simulation environment variables
RUN echo "export TURTLEBOT3_MODEL=waffle" >> ~/.bashrc &&\
    # echo "export GAZEBO_MODEL_PATH=\$GAZEBO_MODEL_PATH:/opt/ros/humble/share/turtlebot3_gazebo/models" >> ~/.bashrc &&\
    # echo "export GAZEBO_MODEL_PATH=\$GAZEBO_MODEL_PATH:~/ros2_ws/src/nav2_simulation/models" >> ~/.bashrc &&\
    echo "export GAZEBO_MODEL_PATH=\$GAZEBO_MODEL_PATH:~/ros2_ws/src/robot_simulator/robot_simulator/worlds/warehouse/models" >> ~/.bashrc &&\
    # echo "export GZ_SIM_RESOURCE_PATH=\$GZ_SIM_RESOURCE_PATH:/usr/share/gz-fortress" >> ~/.bashrc &&\
    # echo "export GZ_SIM_RESOURCE_PATH=\$GZ_SIM_RESOURCE_PATH:/opt/ros/humble/share" >> ~/.bashrc &&\
    echo "export GZ_SIM_RESOURCE_PATH=\$GZ_SIM_RESOURCE_PATH:~/ros2_ws/src/robot_simulator/robot_simulator/worlds/warehouse/models" >> ~/.bashrc &&\
    echo "export IGN_GAZEBO_PHYSICS_ENGINE=bullet" >> ~/.bashrc &&\
    echo "export IGN_GAZEBO_RENDER_ENGINE=ogre" >> ~/.bashrc &&\
    echo "export OGRE_RTT_MODE=Copy" >> ~/.bashrc

# ROS navigation packages
RUN apt-get update && apt-get install -y \
    ros-humble-navigation2 \
    ros-humble-nav2-bringup \
    ros-humble-turtlebot3* \
    ros-humble-rqt* \
    ros-humble-gazebo-ros \
    ros-humble-gazebo-ros2-control \
    ros-humble-tf-transformations \
    ros-humble-rmw-cyclonedds-cpp \
    && rm -rf /var/lib/apt/lists/*

# Python packages
RUN pip install --no-cache-dir \
    jsonschema \
    networkx \
    ruamel.yaml\
    fastapi\
    "uvicorn[standard]"

# Workspace entry point
WORKDIR /ros2_ws

CMD ["bash"]
