cmake_minimum_required(VERSION 3.23)
project(light)

set(CMAKE_CXX_STANDARD 17)

add_executable(light main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

#include_directories(${OPENGL_INCLUDE_DIRS})
#
#target_link_libraries(cuba ${OPENGL_LIBRARIES})

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

target_link_libraries(light ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
