/*
 * File: GameMain.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameMain.h>
#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>
#include <BreakoutLevel.h>

using namespace core;

void GameMain::init() {
    SDL_window* window = SDL_window::create(800, 600);
    width = 800.f;
    height = 600.f;
    glWindow = SDL_GLWindow::create(window);
    glViewport(0, 0, 800, 600);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glm::mat4 projection = glm::ortho(0.f, this->width, this->height, 0.f, -1.f, 1.f);
    resourceBatch.loadShader("shaders/sprite_vertex.glsl", "shaders/sprite_fragment.glsl", "", "sprite");
    resourceBatch.getShader("sprite").use().setInteger("image", 0);
    resourceBatch.getShader("sprite").setMatrix4("projection", projection);
    resourceBatch.loadTexture("textures/block_solid.png", GL_TRUE, "block_solid");
    resourceBatch.loadTexture("textures/block.png", GL_TRUE, "block");
    auto levelone = breakout::Level();
    levelone.load("levels/levelone.json", this->width, this->height * 0.5f, resourceBatch);
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
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    // TODO(): Render stuff



    glWindow->update();
}