cmake_minimum_required(VERSION 3.5)

project(hello_library)

find_package(Boost REQUIRED COMPONENTS)

add_library(hello_library SHARED 
    src/hello.cpp
)
add_library(hello::library ALIAS hello_library)

target_include_directories(hello_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_library(hello_class_form SHARED 
    src/hello_class_form.cpp
)

add_library(hello_class_form::library ALIAS hello_class_form)


add_library(struct_usage SHARED
    src/struct_usage.cpp
)

add_library(please SHARED
    src/please.cpp
)