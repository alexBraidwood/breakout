/*
 * File: GameClock.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_GAMECLOCK_H
#define BREAKOUT_GAMECLOCK_H

#include <chrono>

namespace core {

using timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>;

struct GameClock {
    GameClock() : running(false) {}

    void start();

    void stop();

    float deltaTime();

    bool isRunning() const;

private:
    bool running;
    timestamp startTime;
    timestamp stopTime;
    timestamp lastDt;
};

}

#endif //BREAKOUT_GAMECLOCK_H
