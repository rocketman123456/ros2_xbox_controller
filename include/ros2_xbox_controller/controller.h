#pragma once

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

#include "sensor_msgs/msg/joy.hpp"
#include "teleop_twist_joy/teleop_twist_joy.hpp"

#include "ros2_xbox_controller/controller_constant.h"

namespace Rocket {
    using Result = rcl_interfaces::msg::SetParametersResult;

    class Controller : public rclcpp::Node {
    public:
        Controller(const rclcpp::NodeOptions &node_options = rclcpp::NodeOptions());
        virtual ~Controller();
    
    protected:
        void UpdateControllerData(const sensor_msgs::msg::Joy::SharedPtr msg);

    protected:
        rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
    };
}
