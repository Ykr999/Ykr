#include <ros/ros.h>
#include <my_class_pkg/MyMessage.h>
void callback(const my_class_pkg::MyMessage::ConstPtr& msg)
{
    ROS_INFO("Received: key=%d, value='%s'", msg->key, msg->value.c_str());
}
int main(int argc, char** argv)
{
    // 初始化节点
    ros::init(argc, argv, "my_message_subscriber");
    ros::NodeHandle nh;

    // 订阅话题
    ros::Subscriber sub = nh.subscribe("/my_msg_topic", 10, callback);

    ROS_INFO("Subscriber started, waiting for messages...");
    ros::spin(); // 循环等待回调

    return 0;
}
