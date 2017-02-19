/*
 * File: Texture2d.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Texture2d.h>

using namespace graphics;

Texture2d::Texture2d() {
    glGenTextures(1, &this->id);
}

void Texture2d::generate(GLuint width, GLuint height, unsigned char* data) {
    this->width = width;
    this->height = height;

    // Create Texture
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, this->internalFormat, width, height, 0, this->imageFormat, GL_UNSIGNED_BYTE, data);

    // Set texture wrap and filters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filterMin);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filterMax);

    // Unbind texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2d::bind() const {
    glBindTexture(GL_TEXTURE_2D, this->id);
}