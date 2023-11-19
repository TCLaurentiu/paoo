cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-fno-elide-constructors")

project(my_string)

add_subdirectory(string)
add_subdirectory(MorseCodeString)
include_directories(string MorseCodeString)

add_executable(my_string main.cpp)

target_link_libraries(my_string string morsecodestring)