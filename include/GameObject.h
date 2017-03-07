/*
 * File: GameObject.h.
 * Created by: Alex Braidwood.
 * Date: Mar 07, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_GAMEOBJECT_H
#define BREAKOUT_GAMEOBJECT_H

namespace core {
class GameObject {
public:
    std::string name;
    glm::vec2 position;
    glm::vec2 size;
    glm::vec2 velocity;

    float rotation;
    bool isSolid;
    bool destroyed;

    Texture2D texture;

    GameObject();

    virtual void draw();
};
}

#endif //BREAKOUT_GAMEOBJECT_H
