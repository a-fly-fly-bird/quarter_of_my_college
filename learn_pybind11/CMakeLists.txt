cmake_minimum_required(VERSION 3.4...3.18)
project(example LANGUAGES CXX)

add_subdirectory(extern/pybind11)
pybind11_add_module(example 
    # src/example.cpp 
    src/more_complex_example.cpp
)

pybind11_add_module(test 
    src/return_pointer.cpp
)
