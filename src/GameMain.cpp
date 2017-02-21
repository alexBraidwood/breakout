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
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace core;

void GameMain::init() {
    SDL_window* window = SDL_window::create(800, 600);
    width = 800.f;
    height = 600.f;
    glWindow = SDL_GLWindow::create(window);
    glm::mat4 projection = glm::ortho(0.f, width, height, 0.f, -1.f, 1.f);
}

void GameMain::start() {
    this->state = GameState::Active;
}

void GameMain::processInput(float dt) {

}

void GameMain::update(float dt) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type==SDL_QUIT) {
        state = GameState::Quit;
    }

}

void GameMain::render() {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    // TODO(): Render stuff

    glWindow->update();
}