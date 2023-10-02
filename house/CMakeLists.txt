cmake_minimum_required(VERSION 3.23)
project(house)

set(CMAKE_CXX_STANDARD 17)

add_executable(house main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#include_directories(${OPENGL_INCLUDE_DIRS})
#
#target_link_libraries(cuba ${OPENGL_LIBRARIES})

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(house ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


