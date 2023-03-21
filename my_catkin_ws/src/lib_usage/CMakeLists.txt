cmake_minimum_required(VERSION 3.0.2)
project(lib_usage)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES lib_usage
#  CATKIN_DEPENDS roscpp rospy
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(usage src/usage.cpp)
# include_directories(/home/ty/Desktop/my_catkin_ws/src/lib_study/include/lib_study)

target_link_libraries( usage hello_library ${catkin_LIBRARIES})