from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    param_reader = Node(
        package='my_package',
        executable='param_reader',
        parameters=[{
            'particles': 300,
            'topics': ['scan', 'image'],
            'topic_types': ['sensor_msgs/msg/LaserScan', 'sensor_msgs/msg/Image']
        }],
        output='screen'
    )

    ld = LaunchDescription()
    ld.add_action(param_reader)

    return ld