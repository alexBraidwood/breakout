/*
 * File: GameMain.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameMain.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <Shader.h>
#include <Texture2d.h>

using namespace core;

void GameMain::init() {
    SDL_window* window = SDL_window::create(800, 600);
    glWindow = SDL_GLWindow::create(window);
}

void GameMain::start() {
    this->state = GameState::Active;
}

void GameMain::processInput(float dt) {

}

void GameMain::update(float dt) {
    while(state != GameState::Win) {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            state = GameState::Win;
        }
        glClearColor(0.98f, 0.04f, 0.7f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glWindow->update();
    }
}

void GameMain::render() {

}