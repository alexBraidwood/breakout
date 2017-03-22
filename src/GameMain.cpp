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

GameMain::GameMain() : leftDown(false),
                       rightDown(false),
                       currentLevel(0) { }

void GameMain::init() {

    gameScreen.width = 1280;
    gameScreen.height = 720;
    SDL_window* window = SDL_window::create(this->gameScreen.width, this->gameScreen.height);
    glWindow = SDL_GLWindow::create(window);
    glViewport(0, 0, this->gameScreen.width, this->gameScreen.height);
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glm::mat4 projection = glm::ortho(0.f, static_cast<float>(this->gameScreen.width), static_cast<float>(this->gameScreen.height), 0.f, -1.f, 1.f);
    resourceBatch.loadShader("shaders/sprite_vertex.glsl", "shaders/sprite_fragment.glsl", "", "sprite");
    resourceBatch.getShader("sprite").use().setInteger("image", 0);
    resourceBatch.getShader("sprite").setMatrix4("projection", projection);
    resourceBatch.loadTexture("textures/solid_block.png", GL_TRUE, "solid_block");
    resourceBatch.loadTexture("textures/block.png", GL_TRUE, "block");
    resourceBatch.loadTexture("textures/breakout_paddle.png", GL_TRUE, "playerPaddle");
    resourceBatch.loadTexture("textures/breakout_ball.png", GL_TRUE, "ball");

    breakout::Level levelone;
    levelone.load("levels/levelone.json", this->gameScreen.width, this->gameScreen.height * 0.5f, resourceBatch);
    levels.push_back(levelone);

    playerPaddle = new Paddle("playerPaddle");
    playerPaddle->position(glm::vec2(
            this->gameScreen.width / 2 - playerPaddle->paddleSize.x / 2,
            this->gameScreen.height - playerPaddle->paddleSize.y - 10
    ));
    playerPaddle->init(resourceBatch);

    gameBall = new Ball("ball");
    gameBall->init();
    gameBall->ballGameObject.position = playerPaddle->paddleGameObject.position +
            glm::vec2(playerPaddle->paddleSize.x / 2 - gameBall->radius, -gameBall->radius * 2);

    currentLevel = 1;
}

void GameMain::start() {
    this->state = GameState::Active;
}

void GameMain::processInput(float dt) {
    if (leftDown) {
        this->playerPaddle->move(dt, this->gameScreen.width, true);
    }
    if (rightDown) {
        this->playerPaddle->move(dt, this->gameScreen.width, false);
    }
}

void GameMain::update(float dt) {
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_WINDOWEVENT) {

    }

    if (event.type == SDL_QUIT) {
        state = GameState::Quit;
    }

    if (event.type == SDL_KEYDOWN) {
        // For GUI events
        if (event.key.keysym.sym == SDLK_ESCAPE) {
            // Pop menu instead
            state = GameState::Quit;
        }
    }

    if (event.type == SDL_KEYUP) {
        // For GUI events
    }

    SDL_PumpEvents();
    auto keyStates = SDL_GetKeyboardState(nullptr);
    leftDown = keyStates[SDL_SCANCODE_LEFT] == 1 ;
    rightDown = keyStates[SDL_SCANCODE_RIGHT] == 1;
    gameBall->move(dt, gameScreen);
}

void GameMain::render() {
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    // TODO(): Render stuff
    auto& level = this->levels[currentLevel-1];
    level.draw(resourceBatch);
    playerPaddle->draw(resourceBatch);
    gameBall->draw(resourceBatch);

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