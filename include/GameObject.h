/*
 * File: GameObject.h.
 * Created by: Alex Braidwood.
 * Date: Mar 07, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_GAMEOBJECT_H
#define BREAKOUT_GAMEOBJECT_H

#include <glm/glm.hpp>
#include <string>
#include <Texture2d.h>
#include <Resources.h>

namespace core {
class GameObject {
public:
    std::string spriteName;
    glm::vec2 position;
    glm::vec2 size;
    glm::vec2 velocity;
    glm::vec3 color;

    float rotation;
    bool isSolid;
    bool destroyed;

    graphics::Texture2d texture;

    GameObject(const std::string& spriteName);

    virtual void draw(core::Resources& resourceBatch);
    virtual ~GameObject() = default;
};
}

#endif //BREAKOUT_GAMEOBJECT_H
