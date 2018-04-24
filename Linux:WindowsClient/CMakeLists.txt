cmake_minimum_required(VERSION 3.10)
project(WindowsClient)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(OpenCV REQUIRED)

add_executable(WindowsClient
        Client.cpp
        Client.h
        main.cpp
        MatConverter.cpp
        MatConverter.h
        Networkable.cpp
        Networkable.h
        wrestart.cpp
        wrestart.h)

target_link_libraries(WindowsClient libws2_32.a)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(WindowsClient ${OpenCV_LIBS})