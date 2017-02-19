/*
 * File: SDL_window.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <SDL2/SDL.h>
#include <SDL_window.h>
#include <cassert>
#include <iostream>

using namespace core;

SDL_window::SDL_window(SDL_Window* handle)
    : Handle(handle) { }

SDL_window::~SDL_window() {
    if(handle != nullptr) {
        SDL_DestroyWindow(handle);
    }
}

std::unique_ptr<SDL_window> SDL_window::create(int height, int width) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
        // TODO(Alex): Handle the error here (assert maybe? it shouldn't fail)
        std::cout << "Failed to initialize SDL properly " << SDL_GetError() << std::endl;
    }

    auto window_handle = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_OPENGL);
    assert(window_handle);

    return std::move(std::make_unique<SDL_window>(window_handle));
}
