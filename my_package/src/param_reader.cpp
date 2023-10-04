#include <vector>
#include <string>

#include "rclcpp/rclcpp.hpp"

/*
all parameters of a node must be declared using methods like declare_paramater. In the declaration, we specify the parameter name and the default value
We obtain its value with functions like get_paramater, specifying the name of the parameter and where to store its value
the parameters can be read at any time, even subscribe to modifications in real-time. 
*/

class LocalizationNode : public rclcpp::Node{
private:
    int num_particles_;
    std::vector<std::string> topics_;
    std::vector<std::string> topic_types_;

public:
    LocalizationNode() : Node("localization_node"){
        declare_parameter("number_particles", 200);
        declare_parameter("topics", std::vector<std::string>());
        declare_parameter("topic_types", std::vector<std::string>());

        get_parameter("number_particles", num_particles_);
        RCLCPP_INFO_STREAM(get_logger(), "Number of particles: " << num_particles_);

        get_parameter("topics", topics_);
        get_parameter("topic_types", topic_types_);

        if (topics_.size() != topic_types_.size()){
            RCLCPP_ERROR(get_logger(), "Number of topics (%zu) != number of types (%zu)",
            topics_.size(), topic_types_.size());
        }else{
            RCLCPP_INFO_STREAM(get_logger(), "Number of topics: " << topics_.size());
            for(size_t i = 0; i < topics_.size(); i++){
                RCLCPP_INFO_STREAM(get_logger(), "\t" << topics_[i] << "\t - " << topic_types_[i]);
            }
        }
    }
};

int main(int argc, char * argv[]){
    rclcpp::init(argc, argv);

    auto node = std::make_shared<LocalizationNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}