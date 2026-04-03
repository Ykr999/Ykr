#!/usr/bin/env python3
import rospy
from my_class_pkg.srv import MyServiceMsg

def handle_my_service(req):
    rospy.loginfo("Service request: %d", req.input)
    # 返回计算结果：输入值 × 2
    return req.input * 2  

if __name__ == "__main__":
    # 初始化 ROS 节点
    rospy.init_node("my_service_server")
    # 注册服务：服务名、服务类型、回调函数
    service = rospy.Service("my_service", MyServiceMsg, handle_my_service)
    rospy.loginfo("Ready to handle requests")
    # 保持节点运行，处理请求
    rospy.spin()
