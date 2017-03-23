/*
 * File: BreakoutBall.h.
 * Created by: Alex Braidwood.
 * Date: Mar 20, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_BREAKOUTBALL_H
#define BREAKOUT_BREAKOUTBALL_H

#include <GameObject.h>
#include <Screen.h>
#include <Resources.h>

namespace breakout {
    namespace ball_constants {
        const glm::vec2 InitialBallVelocity(100.f, -350.f);
        const float BallRadius(20.f);
    }
}

namespace breakout {

class Ball {
public:
    float radius;
    bool held;
    core::GameObject ballGameObject;

    Ball(const std::string& spriteName);
    glm::vec2 move(float dt, const core::Screen& screen);
    void reset(glm::vec2 position, glm::vec2 velocity);
    void init(float radius, glm::vec2 velocity, core::Resources& resourceBatch);
    void init(core::Resources& resourceBatch);
    void draw(core::Resources& resourceBatch);
};
}

#endif //BREAKOUT_BREAKOUTBALL_H
