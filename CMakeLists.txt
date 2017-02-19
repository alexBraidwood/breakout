cmake_minimum_required(VERSION 3.6)
project(breakout)

set(CMAKE_CXX_STANDARD 14)

add_executable(breakout "")
add_subdirectory(external/glew/build/cmake)


target_sources(breakout PRIVATE main.cpp src/GameMain.cpp src/Shader.cpp)
target_include_directories(breakout PRIVATE include external/glew/include)
target_link_libraries(breakout PUBLIC glew GL SDL2)