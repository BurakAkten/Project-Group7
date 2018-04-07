cmake_minimum_required(VERSION 3.10)
project(Server)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(OpenCV REQUIRED)

add_executable(Server
        main.cpp
        supporting/restart.c
        supporting/restart.h
        supporting/uici.c
        supporting/uici.h
        supporting/uiciname.c
        supporting/uiciname.h
        MatConverter.cpp
        MatConverter.h
        Server.cpp
        Server.h
        Networkable.cpp
        Networkable.h)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Server ${OpenCV_LIBS})