cmake_minimum_required(VERSION 3.6)
project(breakout)

set(CMAKE_CXX_STANDARD 14)

add_executable(breakout "")
add_subdirectory(external/glew/build/cmake)
find_library(SOIL
        NAMES SOIL libSOIL
        PATHS external/SOIL/lib)

target_sources(breakout PRIVATE
        main.cpp
        src/GameMain.cpp
        src/Shader.cpp
        src/Texture2d.cpp)

target_include_directories(breakout PRIVATE
        include
        external/glew/include
        external/SOIL/src
        external/glm)

target_link_libraries(breakout PUBLIC ${SOIL} glew GL SDL2)