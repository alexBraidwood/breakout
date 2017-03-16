/*
 * File: BreakoutPaddle.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 16, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <BreakoutPaddle.h>

using namespace breakout;


void Paddle::init() {
    paddleGameObject.size = this->paddleSize;
}

void Paddle::position(const glm::vec2& pos) {
    paddleGameObject.position = pos;
}

void Paddle::draw(core::Resources& resourceBatch) {
    this->paddleGameObject.draw(resourceBatch);
}
