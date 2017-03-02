/*
 * File: Sprite.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 21, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Sprite.h>
#include <glm/gtc/matrix_transform.hpp>

using namespace graphics;

void Sprite::init() {
    GLuint VBO;
    GLfloat vertices[] = {
            // Pos    // Texture
            0.f, 1.f, 0.f, 1.f,
            1.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 0.f,

            0.f, 1.f, 0.f, 1.f,
            1.f, 1.f, 1.f, 1.f,
            1.f, 0.f, 1.f, 0.f
    };

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::setTexture(Texture2d& texture) {
    this->texture = texture;
}

void Sprite::draw(glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color) {
    this->shader.use();
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(position, 0.f));

    // Move the origin to the center of the sprite
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.f));
    model = glm::rotate(model, rotation, glm::vec3(0.f, 0.f, 1.f));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.f));

    model = glm::scale(model, glm::vec3(size, -1.f));
    this->shader.setMatrix4("model", model);
    this->shader.setVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    this->texture.bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}