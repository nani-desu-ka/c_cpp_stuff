cmake_minimum_required(VERSION 3.15)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(Calculator src/main.cpp src/SimpleFraction.cpp src/help_functions.cpp src/CustomFloat.cpp
        src/EquationNode.cpp src/EquationTree.cpp
        include/SimpleFraction.hpp include/help_functions.hpp include/CustomFloat.hpp include/EquationNode.hpp
        include/EquationTree.hpp)