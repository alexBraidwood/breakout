/*
 * File: GameObject.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 07, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameObject.h>
#include <Sprite.h>
#include <Resources.h>

GameObject::GameObject(std::string name)
        : position(0, 0), size(1, 1),
          velocity(0.f), color(0.f),
          rotation(0.f), texture(), isSolid(false), destroyed(false) {

}

void GameObject::draw(core::Resources& resourceBatch) {
    if (resourceBatch.getSprite("")) {
        auto sprite = graphics::Sprite(resourceBatch.getShader("sprite"), texture);
    }

}
