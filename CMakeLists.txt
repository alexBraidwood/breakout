cmake_minimum_required(VERSION 3.6)
project(breakout)

set(CMAKE_CXX_STANDARD 14)

add_executable(breakout "")
add_subdirectory(external/glew/build/cmake)
find_library(SOIL
        NAMES SOIL libSOIL
        PATHS external/SOIL/lib)

# Texture file copy-over
# TODO(Alex): compression of textures... one day
file(MAKE_DIRECTORY textures)
file(COPY
        textures/hello.png
        DESTINATION textures/)

# Shader file copy-over
file(MAKE_DIRECTORY shaders)
file(COPY
        shaders/sprite_fragment.glsl
        shaders/sprite_vertex.glsl
        DESTINATION shaders/)

set(CMAKE_C_FLAGS_DEBUG "-DDEBUG")

target_sources(breakout PRIVATE
        main.cpp
        src/GameMain.cpp
        src/Shader.cpp
        src/Texture2d.cpp
        src/Resources.cpp
        src/SDL_window.cpp
        src/SDL_GLWindow.cpp
        src/GameClock.cpp
        src/Sprite.cpp)

target_include_directories(breakout PRIVATE
        include
        external/glew/include
        external/SOIL/src
        external/glm)

MESSAGE(STATUS "Soil found at: " ${SOIL})

target_link_libraries(breakout PUBLIC ${SOIL} glew GL SDL2)