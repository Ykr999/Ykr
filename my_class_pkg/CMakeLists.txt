cmake_minimum_required(VERSION 3.0.2)
project(my_class_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  message_generation
  actionlib
  actionlib_msgs
  dynamic_reconfigure
  tf2_ros
  upros_message
  move_base_msgs

)

generate_dynamic_reconfigure_options(
  cfg/Tutorials.cfg
)

################################################
## Declare ROS messages, services and actions ##
################################################
add_message_files(
  DIRECTORY msg
  FILES MyMessage.msg
)

add_service_files(
  DIRECTORY srv
  FILES MyServiceMsg.srv
)

add_action_files(
  DIRECTORY action
  FILES MyAction.action
)

generate_messages(
  DEPENDENCIES
  std_msgs
  actionlib_msgs
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  CATKIN_DEPENDS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  sensor_msgs
  message_runtime
  actionlib
  actionlib_msgs
  dynamic_reconfigure
  tf2_ros
  upros_message
)

###########
## Build ##
###########
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# 声明可执行文件
add_executable(ros_publisher_node src/ros_publisher.cpp)
add_executable(ros_subscriber_node src/ros_subscriber.cpp)
add_executable(msg_publisher_node src/msg_publisher.cpp)
add_executable(msg_subscriber_node src/msg_subscriber.cpp)
add_executable(ros_server_node src/ros_server.cpp)
add_executable(ros_client_node src/ros_client.cpp)
add_executable(ros_action_server_node src/ros_action_server.cpp)
add_executable(ros_action_client_node src/ros_action_client.cpp)
add_executable(ros_param_node src/ros_param.cpp)
add_executable(dynamic_reconfigure_node src/dynamic_reconfigure.cpp)
add_executable(ros_dynamic_speed_node src/ros_dynamic_speed.cpp)
add_executable(ros_log src/ros_log.cpp)
add_executable(tag_grab_node src/tag_grab.cpp)
add_executable(ros_sonic_node src/ros_sonic.cpp)
add_executable(ros_bump_node src/ros_bump.cpp)
add_executable(ros_imu_node src/ros_imu.cpp)
add_executable(ros_imu_rotate_node src/imu_rotate.cpp)
add_executable(ros_scan_node src/ros_scan.cpp)
add_executable(ros_avoid_node src/ros_avoid.cpp)
add_executable(movebase_client_node src/movebase_client.cpp)
add_executable(tag_voice_node src/tag_voice.cpp)
add_executable(final_node src/final.cpp)
# 链接库
target_link_libraries(ros_publisher_node ${catkin_LIBRARIES})
target_link_libraries(ros_subscriber_node ${catkin_LIBRARIES})
target_link_libraries(msg_publisher_node ${catkin_LIBRARIES})
target_link_libraries(msg_subscriber_node ${catkin_LIBRARIES})
target_link_libraries(ros_server_node ${catkin_LIBRARIES})
target_link_libraries(ros_client_node ${catkin_LIBRARIES})
target_link_libraries(ros_action_server_node ${catkin_LIBRARIES})
target_link_libraries(ros_action_client_node ${catkin_LIBRARIES})
target_link_libraries(ros_param_node ${catkin_LIBRARIES})
target_link_libraries(dynamic_reconfigure_node ${catkin_LIBRARIES})
target_link_libraries(ros_dynamic_speed_node ${catkin_LIBRARIES})
target_link_libraries(ros_log ${catkin_LIBRARIES})
target_link_libraries(tag_grab_node ${catkin_LIBRARIES})
target_link_libraries(ros_sonic_node ${catkin_LIBRARIES})
target_link_libraries(ros_bump_node ${catkin_LIBRARIES})
target_link_libraries(ros_imu_rotate_node ${catkin_LIBRARIES})
target_link_libraries(ros_imu_node ${catkin_LIBRARIES})
target_link_libraries(ros_scan_node ${catkin_LIBRARIES})
target_link_libraries(ros_avoid_node ${catkin_LIBRARIES})
target_link_libraries(movebase_client_node ${catkin_LIBRARIES})
target_link_libraries(tag_voice_node ${catkin_LIBRARIES})
target_link_libraries(final_node ${catkin_LIBRARIES})
# 依赖
add_dependencies(dynamic_reconfigure_node ${PROJECT_NAME}_gencfg)

add_dependencies(ros_publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(msg_publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(msg_subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_action_server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_action_client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(ros_dynamic_speed_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

