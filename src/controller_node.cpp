#include <iostream>

#include "ros2_xbox_controller/controller.h"

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto imu_node = std::make_shared<Rocket::Controller>();
    rclcpp::spin(imu_node);
    rclcpp::shutdown();
    return 0;
}
