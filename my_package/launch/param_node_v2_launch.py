import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    
    pkg_dir = get_package_share_directory('my_package');
    param_file = os.path.join(pkg_dir, 'config', 'params.yaml')

    param_reader = Node(
        package='my_package',
        executable='param_reader',
        parameters=[param_file],
        output='screen'
    )

    ld = LaunchDescription()
    ld.add_action(param_reader)

    return ld