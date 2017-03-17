/*
 * File: BreakoutPaddle.h.
 * Created by: Alex Braidwood.
 * Date: Mar 16, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_BREAKOUTPADDLE_H
#define BREAKOUT_BREAKOUTPADDLE_H

#include <GameObject.h>
#include <glm/glm.hpp>
#include <Resources.h>
#include <memory>

namespace breakout {

class Paddle {
    core::GameObject paddleGameObject;

public:
    /**
     * Constructs a BreakoutPaddle, which manages the game object and houses paddle logic.
     * @param spriteName Name of the sprite to draw as the paddle
     */
    Paddle(const std::string& spriteName)
            : spriteName(spriteName),
              paddleSize(100, 20),
              paddleVelocity(500.f),
              paddleGameObject(core::GameObject(spriteName)) {
    }

    ~Paddle() = default;

    std::string spriteName;
    glm::vec2 paddleSize;
    float paddleVelocity;

    void move(float dt, bool movingLeft);
    void init(core::Resources& resourceBatch);
    void position(const glm::vec2& pos);
    void draw(core::Resources& resourceBatch);
    void update();
};
}

#endif //BREAKOUT_BREAKOUTPADDLE_H
