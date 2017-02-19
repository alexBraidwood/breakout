//
// Created by alex on 2/15/17.
//

#ifndef BREAKOUT_GAMEMAIN_H
#define BREAKOUT_GAMEMAIN_H

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
