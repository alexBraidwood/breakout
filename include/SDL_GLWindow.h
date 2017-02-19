/*
 * File: SDL_GLWindow.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_SDL_GLWINDOW_H
#define BREAKOUT_SDL_GLWINDOW_H

#include <SDL_window.h>

typedef void* SDL_GLContext;

namespace core {

class SDL_GLWindow {
public:
    void update();
    virtual ~SDL_GLWindow();

    SDL_window* get_sdl_window() const;

    /**
     * Factory method for generating GLWindow with an OpenGL-friendly context
     * @param window Pointer to an SDL2 window, used in context creation
     * @return OpenGL-friendly window
     */
    static SDL_GLWindow* create(SDL_window* window);

private:
    SDL_GLWindow(SDL_GLContext context_handle, SDL_window* window);

    SDL_GLContext context;
    SDL_window* window;
    bool loaded_successfully;

    SDL_GLWindow& operator=(SDL_GLWindow&&) = delete;
    SDL_GLWindow(SDL_GLWindow&&) = delete;
    SDL_GLWindow(const SDL_GLWindow&) = delete;
    SDL_GLWindow& operator=(const SDL_GLWindow&) = delete;
};

}


#endif //BREAKOUT_SDL_GLWINDOW_H
