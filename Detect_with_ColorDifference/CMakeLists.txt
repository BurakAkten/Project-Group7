cmake_minimum_required(VERSION 2.8)
project( Detect_with_ColorDifference )
find_package( OpenCV REQUIRED )

add_executable( Detect_with_ColorDifference main.cpp fileContent.cpp fileContent.h)
target_link_libraries( Detect_with_ColorDifference ${OpenCV_LIBS} )

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Detect_with_ColorDifference ${OpenCV_LIBS})