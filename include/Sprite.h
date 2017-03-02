/*
 * File: Sprite.h.
 * Created by: Alex Braidwood.
 * Date: Feb 21, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

/*
  TODO(Alex): Adjust this to better encapsulate Sprites
  TODO(Alex): The Api is just a tad confusing
*/

#ifndef BREAKOUT_SPRITE_H
#define BREAKOUT_SPRITE_H

#include <Texture2d.h>
#include <Shader.h>

namespace graphics {

class Sprite {
public:
    Sprite(Shader& shader, Texture2d& texture) : shader(shader), texture(texture) {}

    ~Sprite() = default;

    /**
     * Sets the texture to be drawn as a sprite
     * @param texture Texture to be drawn as Sprite
     */
    void setTexture(Texture2d& texture);

    /**
     * Draws the sprite with the given parameters
     * @param position Origin of sprite at top-left corner from texture
     * @param size Size of the sprite from the texture (not for scaling)
     * @param rotation Rotation of sprite from center pivot
     * @param color Colors to paint
     */
    void draw(glm::vec2 position,
            glm::vec2 size = glm::vec2(10, 10), float rotation = 0.f,
            glm::vec3 color = glm::vec3(1.f));

private:
    Shader shader;
    GLuint quadVAO;
    Texture2d texture;
    void init();
};

}

#endif //BREAKOUT_SPRITE_H
