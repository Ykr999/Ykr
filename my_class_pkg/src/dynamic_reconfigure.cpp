#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <my_class_pkg/TutorialsConfig.h>

// 回调函数：参数修改时会被调用
void callback(my_class_pkg::TutorialsConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %d %f %s %s %d",
            config.int_param,
            config.double_param,
            config.str_param.c_str(),
            config.bool_param?"True":"False",
            config.size);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "dynamic_tutorials");
  
  // 创建动态参数服务器
  dynamic_reconfigure::Server<my_class_pkg::TutorialsConfig> server;
  dynamic_reconfigure::Server<my_class_pkg::TutorialsConfig>::CallbackType f;

  // 绑定回调函数
  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
