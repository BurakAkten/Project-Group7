cmake_minimum_required(VERSION 3.10)
project(Client)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(OpenCV REQUIRED)

add_executable(Client
        main.cpp
        supporting/restart.c
        supporting/restart.h
        supporting/uici.c
        supporting/uici.h
        supporting/uiciname.c
        supporting/uiciname.h
        MatConverter.cpp
        MatConverter.h
        Networkable.cpp
        Networkable.h
        Client.cpp
        Client.h
        NetworkableException.h)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Client ${OpenCV_LIBS})
