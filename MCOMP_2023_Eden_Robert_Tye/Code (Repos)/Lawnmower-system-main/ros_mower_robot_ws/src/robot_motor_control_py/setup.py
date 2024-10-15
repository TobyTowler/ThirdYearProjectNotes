from setuptools import setup, find_packages

package_name = 'robot_motor_control_py'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='robert',
    maintainer_email='RobertLStevenson01@gmail.com',
    description='An action server node that acts as a bridge for communication with the Robots microcontroller via a serial connection',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robot_bridge = robot_motor_control_py.robot_bridge:main',
            'robot_user_client = robot_motor_control_py.robot_user_client:main',
            'robot_path_provider_client = robot_motor_control_py.robot_path_provider_client:main',
            # 'robot_controller_bridge_server = robot_motor_control_py.robot_controller_bridge_action_server:main',
            # 'robot_controller_bridge_client = robot_motor_control_py.robot_controller_bridge_action_client:main',
        ],
    },
)
