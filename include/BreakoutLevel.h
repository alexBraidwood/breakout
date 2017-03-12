/*
 * File: BreakoutLevel.h.
 * Created by: Alex Braidwood.
 * Date: Mar 03, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_BREAKOUTLEVEL_H
#define BREAKOUT_BREAKOUTLEVEL_H

#include <vector>
#include <string>
#include <GameObject.h>
#include <Resources.h>

namespace breakout {

class Level {
public:
    std::vector<core::GameObject> bricks;
    void load(const std::string& fileName, int levelWidth, int levelHeight, core::Resources& resourceBatch);
    void draw(core::Resources& resourceBatch);
    bool isComplete();
    Level() = default;
    Level(const Level& other);

private:
    void init(const std::vector<std::vector<int>>& tileData, int levelWidth, int levelHeight, core::Resources& resourceBatch);


};

}
#endif //BREAKOUT_BREAKOUTLEVEL_H
