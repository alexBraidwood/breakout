cmake_minimum_required(VERSION 3.6)
project(breakout)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(gamelib)
add_executable(breakout "")

target_sources(breakout PRIVATE main.cpp)
target_include_directories(breakout PRIVATE include gamelib/include)
target_link_libraries(breakout PUBLIC gamelib)