#!/usr/bin/env python3
import rospy
import actionlib

from my_class_pkg.msg import MyActionAction, MyActionGoal, MyActionResult, MyActionFeedback

def feedback_cb(feedback):
    rospy.loginfo('Progress: {}'.format(feedback.progress))

if __name__ == '__main__':
    rospy.init_node('my_client')
    client = actionlib.SimpleActionClient('my_action', MyActionAction)
    
    # 等待服务端启动
    rospy.loginfo('Waiting for action server to start...')
    client.wait_for_server()
    
    # 创建并发送目标
    goal = MyActionGoal()
    goal.object_name = 'world'
    rospy.loginfo('Sending goal...')
    client.send_goal(goal, feedback_cb=feedback_cb)
    
    # 等待结果
    client.wait_for_result()
    
    # 获取并输出结果
    result = client.get_result()
    if result.success:
        rospy.loginfo('Action succeeded')
    else:
        rospy.loginfo('Action failed')
