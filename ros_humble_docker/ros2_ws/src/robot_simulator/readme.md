# ROS 2 Robot Simulator

## Role

- Unified environment for ROS 2 simulation and real robot operation
- Integrates simulator, navigation, mapping, manipulator, and webserver interface

## Structure

```
simul_ws/
└── src/
    ├── robot_simulator/
    │   ├── launch/           # Launch files
    │   ├── param/            # Parameter files
    │   ├── data/             # Data Storage
    │   ├── rviz/             # RViz config
    │   ├── maps/             # Map files
    │   ├── worlds/           # Simulation worlds
    │   ├── robots/           # Robot models
    │   ├── package.xml
    │   └── CMakeLists.txt
    └── dependency_pkgs/
        ├── MOBILE_ROBOT_BASIC/   # Navigation, odometry, etc.
        ├── san_msgs/             # Custom messages
        ├── waypoint_node_manager/ # node calculator
        ├── caselab_rviz2_plugin/ # rviz2 custom plugin
        └── webserver_interface_ros2/
  
```

## Subtree Packages & Branches

- **MOBILE_ROBOT_BASIC**: [robot_simulator branch](https://github.com/raisewise0211/MOBILE_ROBOT_BASIC/tree/robot_simulator)
- **san_msgs**: [master branch](https://github.com/Kwon-SeungWon/san_msgs.git)
- **waypoint_node_manager**: [master branch](https://github.com/Kwon-SeungWon/waypoint_node_manager.git)
- **caselab_rviz2_plugin**: [master branch](https://github.com/cnr-lab/caselab_rviz2_plugin.git)
- **webserver_interface_ros2**: [robot_simulator branch](https://github.com/cnr-lab/webserver_interface_ros2/tree/robot_simulator)

---

## Build

```bash
cd ~/ros2_ws
colcon build --symlink-install
source install/setup.bash
```
---

## Run

- Simulator:
  ```bash
  ros2 launch robot_simulator hamr_simulator.launch.py
  ```
- Core interface:
  ```bash
  ros2 launch amr_core simulator_bringup.launch.py
  ```
- Webserver interface:
  ```bash
  ros2 launch webserver_interface_ros2 webserver_interface_launch.py
  ```
- Rviz:
  ```bash
  ros2 launch caselab_rviz_plugin test.launch.py 
  ```

---

## Delete Source file
  ```bash
  chmod +x delete_source.sh
  ./delete_source.sh
  ```

---


## 소스코드 보호 및 Cython 배포 (waypoint_node_manager 예시)

### 목적
- Python 소스코드(.py) 노출 없이 ROS2 노드를 배포/실행
- Cython으로 .so 파일만 배포하여 역공학 난이도 상승

### 절차 요약
1. **Cython 설치**
   ```bash
   pip install cython
   ```
2. **.py → .pyx 복사**
   ```bash
   cp waypoint_node_manager.py waypoint_node_manager.pyx
   ```
3. **setup_cython.py 작성** (예시)
   ```python
   from setuptools import setup, Extension
   from Cython.Build import cythonize
   import numpy
   extensions = [
       Extension(
           "waypoint_node_manager.waypoint_node_manager",
           ["waypoint_node_manager/waypoint_node_manager.pyx"],
           include_dirs=[numpy.get_include()],
           extra_compile_args=["-O3"],
       )
   ]
   setup(
       name="waypoint_node_manager",
       ext_modules=cythonize(
           extensions,
           compiler_directives={
               'language_level': "3",
               'boundscheck': True,
               'wraparound': True,
               'initializedcheck': True,
               'nonecheck': True,
           }
       ),
       zip_safe=False,
   )
   ```
4. **Cython 빌드**
   ```bash
   python3 setup_cython.py build_ext --inplace
   ```
5. **소스코드(.py, .pyx) 삭제 및 .so만 배포**
   - 단, ROS2 노드 엔트리포인트용 최소 .py 파일은 남겨야 함
   - 예시:
     ```python
     # waypoint_node_manager.py
     from .waypoint_node_manager import main
     if __name__ == "__main__":
         main()
     ```

### Troubleshooting
- **Logger 에러**: `self.get_logger()` 대신 `self.logger = self.get_logger()` 후 `self.logger.info()` 등으로 사용
- **Segmentation Fault**: Cython 빌드 시 `compiler_directives`에서 boundscheck 등 안전 옵션 활성화, try-except로 시각화 함수 감싸기
- **서비스 미등록**: .so만 남기면 노드가 실행되지 않을 수 있으니, 최소 엔트리포인트 .py 파일을 남길 것
- **리소스 파일 경로**: yaml 등 리소스 파일이 install/share/패키지명/에 반드시 존재해야 함

### 배포 예시 구조
```
waypoint_node_manager/
  waypoint_node_manager/
    __init__.py
    waypoint_node_manager.cpython-310-x86_64-linux-gnu.so
    waypoint_node_manager.py  # (엔트리포인트)
  setup_cython.py
  (리소스 yaml 등)
```
---