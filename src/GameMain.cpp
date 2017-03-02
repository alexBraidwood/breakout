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
#include <Sprite.h>

using namespace core;

void GameMain::init() {
    SDL_window* window = SDL_window::create(800, 600);
    width = 800.f;
    height = 600.f;
    glWindow = SDL_GLWindow::create(window);
    glm::mat4 projection = glm::ortho(0.f, this->width, this->height, 0.f, -1.f, 1.f);
    resourceBatch.loadShader("shaders/sprite_vertex.glsl", "shaders/sprite_fragment.glsl", "", "sprite");
    resourceBatch.getShader("sprite").use().setInteger("image", 0);
    resourceBatch.getShader("sprite").setMatrix4("projection", projection);
    resourceBatch.loadTexture("textures/hello.png", GL_TRUE, "hello");
    auto sprite = graphics::Sprite(resourceBatch.getShader("sprite"), resourceBatch.getTexture("hello"));
    resourceBatch.addSprite(sprite, "hello_sprite");
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
//    glClearColor(1.f, 1.f, 1.f, 1.f);
//    glClear(GL_COLOR_BUFFER_BIT);
    // TODO(): Render stuff
    resourceBatch.getSprite("hello_sprite").draw(
            glm::vec2(200, 200),
            glm::vec2(300, 400),
            0.f,
            glm::vec3(0.f, 1.f, 0.f));


    glWindow->update();
}