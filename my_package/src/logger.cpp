#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[]){

    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("Logger_node");

    rclcpp::Rate loop_rate(1s);

    int counter = 0; 

    while(rclcpp::ok()){

        RCLCPP_DEBUG(node->get_logger(), "Hello %d", counter++);
        rclcpp::spin_some(node);

        loop_rate.sleep();
    }

    return 0;
    rclcpp::shutdown();
}