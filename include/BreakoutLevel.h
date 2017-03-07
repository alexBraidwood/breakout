/*
 * File: BreakoutLevel.h.
 * Created by: Alex Braidwood.
 * Date: Mar 03, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_BREAKOUTLEVEL_H
#define BREAKOUT_BREAKOUTLEVEL_H

namespace breakout {

class Level {
public:
    std::vector <GameObject> bricks;

    static void load(const std::string& fileName, int levelWidth, int levelHeight);

    void draw();

    bool isComplete();

private:
    void init(std::vector <std::vector<int>> tileData, int levelWidth, int levelHeight);

    GameLevel() = default;
};

}
#endif //BREAKOUT_BREAKOUTLEVEL_H
