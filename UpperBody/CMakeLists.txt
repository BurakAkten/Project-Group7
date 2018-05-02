cmake_minimum_required(VERSION 3.9)
project(UpperBody)

find_package( OpenCV REQUIRED )
set(CMAKE_CXX_STANDARD 11)

add_executable(UpperBody main.cpp)


target_link_libraries(UpperBody ${OpenCV_LIBS} )

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(UpperBody ${OpenCV_LIBS})