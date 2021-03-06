/*
 * File: BreakoutPaddle.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 16, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <BreakoutPaddle.h>

using namespace breakout;


void Paddle::init(core::Resources& resourceBatch) {
    paddleGameObject.size = this->paddleSize;
    paddleGameObject.color = glm::vec3(0.8f, 0.5f, 0.5f);
    paddleGameObject.texture = resourceBatch.getTexture(spriteName);
}

void Paddle::position(const glm::vec2& pos) {
    paddleGameObject.position = pos;
}

float Paddle::move(float dt, int screenWidth, bool movingLeft) {
    auto velocity = movingLeft ? -paddleVelocity : paddleVelocity;
    auto originalPos = paddleGameObject.position.x;
    auto destination = originalPos + (velocity * dt);
    if (destination > screenWidth - paddleSize.x || destination < 0) {
        destination = originalPos;
    }
    auto lerp = (destination - originalPos);
    this->paddleGameObject.position.x += lerp;
	return lerp;
}

void Paddle::draw(core::Resources& resourceBatch) {
    this->paddleGameObject.draw(resourceBatch);
}
