cmake_minimum_required(VERSION 3.10)
project(Motor)

set(CMAKE_CXX_STANDARD 11)

add_executable(Motor main.cpp Motor.cpp Motor.h MotorException.h)