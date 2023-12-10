cmake_minimum_required(VERSION 3.10)

project(word_analysis)
add_subdirectory(TextLoader)
include_directories(TextLoader)

add_executable(word_analysis main.cpp)
target_link_libraries(word_analysis textloader)