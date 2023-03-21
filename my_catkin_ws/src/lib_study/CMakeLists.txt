cmake_minimum_required(VERSION 3.0.2)
project(lib_study)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES lib_study
  CATKIN_DEPENDS roscpp rospy
  DEPENDS system_lib
)

include_directories( include
  ${catkin_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_library(hello_library STATIC 
    src/hello.cpp
    # include/lib_study/hello.h
)

target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(use_hello src/use_hello.cpp)

target_link_libraries( use_hello ${catkin_LIBRARIES} hello_library)
