/*
 * File: Sprite.h.
 * Created by: Alex Braidwood.
 * Date: Feb 21, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

/*
  TODO(Alex): Adjust this to better encapsulate Sprites
*/

#ifndef BREAKOUT_SPRITE_H
#define BREAKOUT_SPRITE_H

namespace graphics {

class Sprite {
public:
    Sprite(Shader& shader);

    ~Sprite();

    void draw(Texture2d& texture, glm::vec2 position,
            glm::vec2 size = glm::vec2(10, 10), float rotation = 0.f,
            glm::vec3 color = glm::vec3(1.f));

private:
    Shader shader;
    GLuint quadVAO;

    void init();
};

}

#endif //BREAKOUT_SPRITE_H
