#include <ros/ros.h>
#include <my_class_pkg/MyMessage.h>  


int main(int argc, char** argv)
{
    // 初始化ROS节点，命名为"my_message_publisher"
    ros::init(argc, argv, "my_message_publisher");
    ros::NodeHandle nh;

    // 创建发布者：话题名"/my_msg_topic"，消息类型my_class_pkg::MyMessage，队列大小10
    ros::Publisher pub = nh.advertise<my_class_pkg::MyMessage>("/my_msg_topic", 10);

    // 设置发布频率为1Hz（每秒发布1次）
    ros::Rate rate(1);
    int key = 0;

    while (ros::ok())  // 节点正常运行时循环
    {
        // 创建自定义消息对象并赋值
        my_class_pkg::MyMessage msg;
        msg.key = key;
        msg.value = "Hello from C++ publisher, key = " + std::to_string(key);

        // 打印发布日志
        ROS_INFO("Publishing: key=%d, value='%s'", msg.key, msg.value.c_str());
        // 发布消息
        pub.publish(msg);

        ++key;
        rate.sleep();  // 按设定频率休眠，保证发布节奏
    }

    return 0;
}
