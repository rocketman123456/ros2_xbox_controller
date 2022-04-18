#include "ros2_xbox_controller/controller.h"

#include <functional>
#include <iostream>

namespace Rocket {
    Controller::Controller(const rclcpp::NodeOptions &node_options) 
            : Node("xbox_controller", "/", node_options) {
        std::function<void(const sensor_msgs::msg::Joy::SharedPtr)> controller_callback = 
            std::bind(&Controller::UpdateControllerData, this, std::placeholders::_1);
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "joy", 
            rclcpp::QoS(10), 
            controller_callback
        );
    }

    Controller::~Controller() {
    }

    void Controller::UpdateControllerData(const sensor_msgs::msg::Joy::SharedPtr msg) {
        RCLCPP_INFO(this->get_logger(), "AXIS : %d, BUTTON : %d", msg->axes.size(), msg->buttons.size());
        std::cout << "axis: ";
        for(auto axis : msg->axes) {
            std::cout << axis << ", ";
        }
        std::cout << " button: ";
        for(auto button : msg->buttons) {
            std::cout << button << ", ";
        }
        std::cout << std::endl;

        // TODO : send data to serial port
    }
}
