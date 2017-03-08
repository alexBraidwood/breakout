/*
 * File: GameObject.cpp.
 * Created by: Alex Braidwood.
 * Date: Mar 07, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <GameObject.h>

using namespace core;

GameObject::GameObject(const std::string& name)
        : name(name), position(0, 0), size(1, 1),
          velocity(0.f), color(0.f),
          rotation(0.f), texture(), isSolid(false), destroyed(false) {

}

void GameObject::draw(core::Resources& resourceBatch) {
    // TODO(Alex): Move out into an initialization routine.
    if (resourceBatch.sprites.find(name) == resourceBatch.sprites.end()) {
        auto sprite = graphics::Sprite(resourceBatch.getShader("sprite"), texture);
        resourceBatch.addSprite(sprite, name);
    }
    resourceBatch.getSprite(name).draw(this->position, this->size, this->rotation, this->color);
}
