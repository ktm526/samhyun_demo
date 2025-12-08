from setuptools import find_packages, setup, Extension
from Cython.Build import cythonize
import numpy
from glob import glob

package_name = 'webserver_interface_ros2'

extensions = [
    # 보호할 모듈들
    Extension(
        "webserver_interface_ros2.node_manager_",
        ["webserver_interface_ros2/node_manager_.pyx"],
        include_dirs=[numpy.get_include()],
        extra_compile_args=["-O3"],
    ),
    Extension(
        "webserver_interface_ros2.server_",
        ["webserver_interface_ros2/server_.pyx"],
        include_dirs=[numpy.get_include()],
        extra_compile_args=["-O3"],
    ),
    Extension(
        "webserver_interface_ros2.ros_handler_",
        ["webserver_interface_ros2/ros_handler_.pyx"],
        include_dirs=[numpy.get_include()],
        extra_compile_args=["-O3"],
    ),
    Extension(
        "webserver_interface_ros2.vda5050_manager_",
        ["webserver_interface_ros2/vda5050_manager_.pyx"],
        include_dirs=[numpy.get_include()],
        extra_compile_args=["-O3"],
    ),
]

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    # Cython 확장 모듈을 함께 빌드하도록 지정
    ext_modules=cythonize(
        extensions,
        compiler_directives={'language_level': "3"}
    ),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/json_schemas', glob('json_schemas/*')),
        ('share/' + package_name + '/config', glob('config/*')),
        ('share/' + package_name + '/nodes', glob('nodes/*')),
        ('share/' + package_name + '/maps', glob('maps/*')),
        ('share/' + package_name + '/launch', glob('launch/*')),
    ],
    setup_requires=['cython', 'numpy'],
    install_requires=['setuptools', 'cython', 'numpy'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='asdasd0111@naver.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'webserver_interface = webserver_interface_ros2.webserver_interface:main',
            'ros_handler = webserver_interface_ros2.ros_handler:main',
            'node_manager = webserver_interface_ros2.node_manager:main',
            'server = webserver_interface_ros2.server:main',
        ],
    },
)
