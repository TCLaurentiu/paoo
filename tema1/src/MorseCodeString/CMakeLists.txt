cmake_minimum_required(VERSION 3.10)
add_library(morsecodestring morsecodestring.cpp)
target_link_libraries(morsecodestring string)
target_include_directories(morsecodestring ../string/)