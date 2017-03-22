/*
 * File: GameObject.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 07, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameObject.h>

using namespace core;

GameObject::GameObject(const std::string& spriteName)
        : spriteName(spriteName), position(0, 0), size(1, 1),
          velocity(0.f), color(0.f),
          rotation(0.f), texture(), isSolid(false), destroyed(false) {

}

void GameObject::draw(core::Resources& resourceBatch) {
    // TODO(Alex): Move out into an initialization routine.
    if (resourceBatch.sprites.find(spriteName) == resourceBatch.sprites.end()) {
        auto sprite = graphics::Sprite(resourceBatch.getShader("sprite"), texture);
        resourceBatch.addSprite(sprite, spriteName);
    }
    resourceBatch.getSprite(spriteName).draw(this->position, this->size, this->rotation, this->color);
}
