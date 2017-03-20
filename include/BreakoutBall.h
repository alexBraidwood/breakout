/*
 * File: BreakoutBall.h.
 * Created by: Alex Braidwood.
 * Date: Mar 20, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_BREAKOUTBALL_H
#define BREAKOUT_BREAKOUTBALL_H

#include <GameObject.h>

namespace breakout {
class Ball {
    core::GameObject ballGameObject;

public:
    float radius;
    bool held;

    Ball();
    Ball(const std::string& spriteName, glm::vec2 position, float radius, glm::vec2 velocity);

    glm::vec2 move(float dt, int screenWidth);
    void reset(glm::vec2 position, glm::vec2 velocity);
};
}

#endif //BREAKOUT_BREAKOUTBALL_H
