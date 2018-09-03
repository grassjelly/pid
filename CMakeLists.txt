cmake_minimum_required(VERSION 2.8.3)
project(lino_pid)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  roscpp
  rospy
  lino_msgs
)

find_package(catkin REQUIRED COMPONENTS 
  dynamic_reconfigure 
  rospy
  roscpp 
  lino_msgs
)

generate_dynamic_reconfigure_options(
   cfg/LinoPID.cfg
 )

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(lino_pid src/lino_pid.cpp)
add_executable(pid_configure src/pid_configure.cpp)
target_link_libraries(pid_configure lino_pid ${catkin_LIBRARIES})
