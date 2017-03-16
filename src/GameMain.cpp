/*
 * File: GameMain.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameMain.h>
#include <SDL2/SDL.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace core;
using namespace breakout;

GameMain::GameMain() : currentLevel(0) { }

void GameMain::init() {

    width = 1280.f;
    height = 720.f;
    SDL_window* window = SDL_window::create(this->width, this->height);
    glWindow = SDL_GLWindow::create(window);
    glViewport(0, 0, this->width, this->height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glm::mat4 projection = glm::ortho(0.f, this->width, this->height, 0.f, -1.f, 1.f);
    resourceBatch.loadShader("shaders/sprite_vertex.glsl", "shaders/sprite_fragment.glsl", "", "sprite");
    resourceBatch.getShader("sprite").use().setInteger("image", 0);
    resourceBatch.getShader("sprite").setMatrix4("projection", projection);
    resourceBatch.loadTexture("textures/solid_block.png", GL_TRUE, "solid_block");
    resourceBatch.loadTexture("textures/block.png", GL_TRUE, "block");
    resourceBatch.loadTexture("textures/breakout_paddle.png", GL_TRUE, "playerPaddle");

    breakout::Level levelone;
    levelone.load("levels/levelone.json", this->width, this->height * 0.5f, resourceBatch);
    levels.push_back(levelone);

    playerPaddle = new Paddle("playerPaddle");
    playerPaddle->position(glm::vec2(
            this->width / 2 - playerPaddle->paddleSize.x / 2,
            this->height - playerPaddle->paddleSize.y - 10
    ));
    playerPaddle->init(resourceBatch);

    currentLevel = 1;
}

void GameMain::start() {
    this->state = GameState::Active;
}

void GameMain::processInput(float dt) {

}

void GameMain::update(float dt) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_WINDOWEVENT) {
        if (event.window.type==SDL_QUIT) {
            state = GameState::Quit;
        }
    }
    if (event.type == SDL_KEYDOWN) {
        // Handle key press
    }

    if (event.type == SDL_KEYUP) {
        // Handle key release
    }

}

void GameMain::render() {
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    // TODO(): Render stuff
    auto& level = this->levels[currentLevel-1];
    level.draw(resourceBatch);
    playerPaddle->draw(resourceBatch);

    glWindow->update();
}

GameMain::~GameMain() {
    if (glWindow) {
        delete glWindow;
    }
    if (playerPaddle) {
        delete playerPaddle;
    }
}