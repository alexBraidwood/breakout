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
#include <Screen.h>
#include <BreakoutLevel.h>
#include <BreakoutPaddle.h>
#include <BreakoutBall.h>

namespace core {

class GameMain {
public:
    bool leftDown;
    bool rightDown;
	bool spaceDown;

    breakout::Paddle* playerPaddle;
    breakout::Ball* gameBall;
    SDL_GLWindow* glWindow;
    std::vector<breakout::Level> levels;
    int currentLevel;
    Resources resourceBatch;
    GameState state;
    Screen gameScreen;
	
	bool isColliding(const GameObject& objectA, const GameObject& objectB);
	bool isColliding(const breakout::Ball& ball, const GameObject& objectB);
	void checkCollisions();
    void start();
    void init();
    void processInput(float dt);
    void update(float dt);
    void render();
    GameMain();
    ~GameMain();
};

}

#endif //BREAKOUT_GAMEMAIN_H
