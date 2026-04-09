#include <ros/ros.h>
#include <std_msgs/Bool.h>  // 根据你的消息类型修改

// 提前声明/定义回调函数
void bumpCallback(const std_msgs::Bool::ConstPtr& msg) {
    // 你的回调逻辑
    ROS_INFO("Bump sensor triggered!");
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "ros_bump_node");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/robot/bump_sensor", 1000, bumpCallback);

    ros::spin();
    return 0;
}
