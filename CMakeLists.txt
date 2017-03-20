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
        textures/block.png
        textures/solid_block.png
        textures/breakout_paddle.png
        DESTINATION textures/)

# Shader file copy-over
file(MAKE_DIRECTORY shaders)
file(COPY
        shaders/sprite_fragment.glsl
        shaders/sprite_vertex.glsl
        DESTINATION shaders/)

# Level file copy-over
file(MAKE_DIRECTORY levels)
file(COPY
        levels/levelone.json
        DESTINATION levels/)

set(CMAKE_C_FLAGS_DEBUG "-DDEBUG")

target_sources(breakout PRIVATE
        # Headers
        include/BreakoutBall.h
        include/BreakoutLevel.h
        include/BreakoutPaddle.h
        include/GameClock.h
        include/GameMain.h
        include/GameObject.h
        include/GameState.h
        include/Resources.h
        include/SDL_GLWindow.h
        include/SDL_window.h
        include/Shader.h
        include/Sprite.h
        include/Texture2d.h

        # Source Files
        main.cpp
        src/GameMain.cpp
        src/Shader.cpp
        src/Texture2d.cpp
        src/Resources.cpp
        src/SDL_window.cpp
        src/SDL_GLWindow.cpp
        src/GameClock.cpp
        src/Sprite.cpp
        src/GameObject.cpp
        src/BreakoutLevel.cpp
        src/BreakoutPaddle.cpp
        src/BreakoutBall.cpp)



target_include_directories(breakout PRIVATE
        include
        external/glew/include
        external/SOIL/src
        external/glm
        external/rapidjson)

MESSAGE(STATUS "Soil found at: " ${SOIL})

target_link_libraries(breakout PUBLIC ${SOIL} glew GL SDL2)