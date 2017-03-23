/*
 * File: BreakoutBall.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 20, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <BreakoutBall.h>

using namespace breakout;
using namespace core;

Ball::Ball(const std::string& spriteName) : ballGameObject(spriteName), radius(0), held(true) {}

void Ball::init(Resources& resourceBatch) {
    this->init(ball_constants::BallRadius, ball_constants::InitialBallVelocity, resourceBatch);
}

void Ball::init(float radius, glm::vec2 velocity, Resources& resourceBatch) {
    this->radius = radius;
    this->ballGameObject.size.x = radius;
    this->ballGameObject.size.y = radius;
    this->ballGameObject.color = glm::vec3(1.f, 0.5f, 1.f);
    this->ballGameObject.texture = resourceBatch.getTexture(this->ballGameObject.spriteName);
    this->ballGameObject.velocity = velocity;
}

glm::vec2 Ball::move(float dt, const Screen& gameScreen) {
    GameObject& ballGameObject = this->ballGameObject;

    if (!this->held) {
        ballGameObject.position += ballGameObject.velocity * dt;

        // Handle wall and ceiling bouncing
        if (ballGameObject.position.x <= 0.f) {
            ballGameObject.velocity = -ballGameObject.velocity;
            ballGameObject.position.x = 0.f;
        }
        else if (ballGameObject.position.x + ballGameObject.size.x >= gameScreen.width) {
            ballGameObject.velocity.x = -ballGameObject.velocity.x;
            ballGameObject.position.x = gameScreen.width - ballGameObject.size.x;
        }

        if (ballGameObject.position.y <= 0.f) {
            ballGameObject.velocity.y = -ballGameObject.velocity.y;
            ballGameObject.position.y = 0.f;
        }
    }

    return ballGameObject.position;
}

void Ball::reset(glm::vec2 position, glm::vec2 velocity) {
    GameObject& ballGameObject = this->ballGameObject;
    ballGameObject.position = position;
    ballGameObject.velocity = velocity;
    this->held = false;
}

void Ball::draw(Resources& resourceBatch) {
    this->ballGameObject.draw(resourceBatch);
}