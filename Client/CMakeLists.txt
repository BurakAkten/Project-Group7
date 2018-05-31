cmake_minimum_required(VERSION 3.10)
project(LinuxWindowsClient)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

find_package(OpenCV REQUIRED)

add_executable(LinuxWindowsClient
        main.cpp
        Client.cpp
        Client.h
        MatConverter.cpp
        MatConverter.h
        Networkable.cpp
        Networkable.h
        supporting/wrestart.cpp
        supporting/wrestart.h
        supporting/restart.c
        supporting/restart.h
        supporting/uici.c
        supporting/uici.h
        supporting/uiciname.c
        supporting/uiciname.h
        NetworkableException.h
        Command.h
        Data.h)


IF(WIN32)
    target_link_libraries(LinuxWindowsClient libws2_32.a)
ENDIF(WIN32)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(LinuxWindowsClient ${OpenCV_LIBS})