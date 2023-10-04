from launch import LaunchDescription
from launch_ros.actions import Node

# a launch is a Python program that contains a generate_launch_Description()
# function that returns a LaunchDescription object. A LaunchDescription 
# object contains actions


def generate_launch_description():

    pub_cmd = Node(
        package='my_package',
        executable='publisher_class',
        output='screen'
    )

    sub_cmd = Node(
        package='my_package',
        executable='subscriber_class',
        output='screen'
    )

    ld = LaunchDescription()
    ld.add_action(pub_cmd)
    ld.add_action(sub_cmd)

    return ld