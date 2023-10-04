from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    return LaunchDescription([
        Node(
            package='my_package',
            executable='publisher_class',
            output='screen'
        ),
        Node(
            package='my_package',
            executable='subscriber_class',
            output='screen'
        )
    ])