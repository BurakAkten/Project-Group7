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
        Networkable.h
        NetworkableException.h
        Command.h
        Data.h
        motor/Motor.cpp
        motor/Motor.h
        motor/MotorException.h
        image/Detected.h
        image/Detected.cpp
        image/Recognation.h
        image/Recognation.cpp
        image/variables.h
#        db/dbconnection.h
#        db/dbconnection.cpp
        )

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Server ${OpenCV_LIBS})