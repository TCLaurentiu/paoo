cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(word_analysis)
add_subdirectory(TextLoader)
include_directories(TextLoader)

add_executable(word_analysis main.cpp)
find_package(Threads)
target_link_libraries(word_analysis textloader Threads::Threads)