cmake_minimum_required(VERSION 3.21) #最低CMake版本

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

# Enable C++11
set(CMAKE_CXX_STANDARD 11)

project(homework_3_demo) # 工程名

set(SOURCES
    src/li_dar.cc
    src/main.cc
    src/under_pan.cc
)#创建一个变量，名字叫SOURCE。它包含了所有的cpp文件

add_executable(subscriber_pattern ${SOURCES})#用所有的源文件生成一个可执行文件，因为这里定义了SOURCE变量，所以就不需要罗列cpp文件了

target_include_directories(subscriber_pattern
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)#设置这个可执行文件hello_headers需要包含的库的路径

#PROJECT_SOURCE_DIR指工程顶层目录
#PRIVATE指定了库的范围
