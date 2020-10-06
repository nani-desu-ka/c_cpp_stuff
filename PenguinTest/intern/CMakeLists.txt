cmake_minimum_required(VERSION 3.15)
project(penguin_test)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(penguin_test src/main.cpp src/TextToken.cpp include/TextToken.hpp)