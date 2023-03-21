cmake_minimum_required(VERSION 3.0.2)
project(pcl_study)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  pcl_ros
  sensor_msgs
)

find_package(PCL REQUIRED) # This includes all modules

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES pcl_study
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_executable(pcl_viewer src/pcl_viewer.cpp)
target_link_libraries(pcl_viewer ${catkin_LIBRARIES} ${PCL_LIBRARIES})