cmake_minimum_required(VERSION 3.9)
project(RecognationModule)

find_package( OpenCV REQUIRED )
set(CMAKE_CXX_STANDARD 11)

add_executable(RecognationModule main.cpp Recognation.cpp Recognation.h variables.h Detected.cpp Detected.h)
target_link_libraries(RecognationModule ${OpenCV_LIBS} )
include_directories(${OpenCV_INCLUDE_DIRS})