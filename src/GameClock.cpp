/*
 * File: GameClock.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameClock.h>

using namespace std::chrono;
using namespace core;

void GameClock::start() {
    running = true;
    startTime = high_resolution_clock::now();
    lastDt = startTime;
}

void GameClock::stop() {
    running = false;
    stopTime = startTime;
    startTime = timestamp();
}

float GameClock::deltaTime() {
    auto currentDt = high_resolution_clock::now();
    auto diff = duration_cast<nanoseconds>(currentDt - lastDt);
    lastDt = currentDt;
    float dt = diff.count() / 1000000000.f;
    return dt;
}

bool GameClock::isRunning() const {
    return running;
}