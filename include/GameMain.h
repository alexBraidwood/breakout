/*
 * File: GameMain.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef BREAKOUT_GAMEMAIN_H
#define BREAKOUT_GAMEMAIN_H

#include <GameState.h>
#include <SDL_GLWindow.h>
#include <Resources.h>
#include <vector>
#include <BreakoutLevel.h>

namespace core {

class GameMain {
public:
    SDL_GLWindow* glWindow;
    std::vector<breakout::Level> levels;
    int currentLevel;
    Resources resourceBatch;
    GameState state;
    float width, height;

    void start();
    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
    GameMain();
};

}

#endif //BREAKOUT_GAMEMAIN_H
