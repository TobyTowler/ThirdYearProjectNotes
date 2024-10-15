from setuptools import setup, find_packages

package_name = 'path_nav'

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
    maintainer='tye',
    maintainer_email='buckingham.t.g@gmail.com',
    description='Robot Navigation',
    license='GLPv3',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'robot_nav = path_nav.lidar_sim:main',
        ],
    },
)
