/*
 * File: GameMain.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef BREAKOUT_GAMEMAIN_H
#define BREAKOUT_GAMEMAIN_H

#include <GameState.h>

namespace core {

class GameMain {
public:
    GameState state;
    int width, height;

    void start();
    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
};

}

#endif //BREAKOUT_GAMEMAIN_H
