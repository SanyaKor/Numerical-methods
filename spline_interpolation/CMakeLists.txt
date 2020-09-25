cmake_minimum_required(VERSION 3.14)
project(cube_splines)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp spline.cpp spline.h plotter.cpp plotter.h)
add_executable(cube_splines ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(cube_splines sfml-system sfml-window sfml-graphics sfml-audio sfml-network)