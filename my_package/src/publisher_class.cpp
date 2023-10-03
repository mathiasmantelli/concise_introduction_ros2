#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using namespace std::chrono_literals;

using std::placeholders::_1;

class PublisherNode : public rclcpp::Node{
private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std_msgs::msg::Int32 message_; //this is the int32 message that contains only one data field. It is published every 500 ms

public:
    PublisherNode() : Node("publisher_node"){
        //this is a public method from rclcpp::Node. It returns a shared_ptr to an rclcpp::Publisher object
        //the arguments are the name of the topic and an rclcpp::QoS object. The class also takes an integer that is the size of the output message queue for that topic
        //we can select different QoS
        publisher_ = create_publisher<std_msgs::msg::Int32>("int_topic", 10); 
        timer_ = create_wall_timer(500ms, std::bind(&PublisherNode::timer_callback, this));
    }

    void timer_callback(){
        message_.data += 1; 
        publisher_->publish(message_);
    }
};

int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);

    auto node = std::make_shared<PublisherNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}