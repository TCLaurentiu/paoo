cmake_minimum_required(VERSION 3.10)
add_library(stringinthashmap stringinthashmap.cpp)

target_link_libraries(stringinthashmap PUBLIC linkedlist)
target_include_directories(stringinthashmap PUBLIC ../LinkedList/)