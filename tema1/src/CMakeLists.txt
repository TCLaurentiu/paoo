cmake_minimum_required(VERSION 3.10)

project(my_string)

add_subdirectory(string)
include_directories(string)

add_executable(my_string main.cpp)

target_link_libraries(my_string string)