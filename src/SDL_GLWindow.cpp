/*
 * File: SDL_GLWindow.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <SDL_GLWindow.h>
#include <SDL2/SDL.h>
#include <SDL_window.h>
#include <GL/glew.h>
using namespace core;

SDL_GLWindow::SDL_GLWindow(SDL_GLContext context_handle, SDL_window* window)
        :   context(context_handle),
            loaded_successfully(false),
            window(window)  {

}

SDL_GLWindow::~SDL_GLWindow() {
    if (this->context != nullptr) {
        SDL_GL_DeleteContext(this->context);
    }
    if (this->window != nullptr) {
        delete window;
    }
}

void SDL_GLWindow::update() {
    SDL_GL_SwapWindow(window->get());
}

SDL_GLWindow* SDL_GLWindow::create(SDL_window* window) {
    if(window) {
        /* TODO(Alex): GL Settings */
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        auto glContext = SDL_GL_CreateContext(window->get());

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if (err != GLEW_OK)
        {
            auto error = glewGetErrorString(err);
        }

        return new SDL_GLWindow(glContext, window);
    }

    return nullptr;
}

SDL_window* SDL_GLWindow::get_sdl_window() const {
    return window;
}


