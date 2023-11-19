cmake_minimum_required(VERSION 3.10)
add_library(checksumstring checksumstring.cpp)
target_link_libraries(checksumstring PUBLIC string)
target_include_directories(checksumstring PUBLIC ../string/)