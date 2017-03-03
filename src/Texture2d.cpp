/*
 * File: Texture2d.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Texture2d.h>
#include <SOIL.h>
#include <cassert>
#include <fstream>

using namespace graphics;

Texture2d::Texture2d()
    : width(0), height(0),
      internalFormat(GL_RGB), imageFormat(GL_RGB),
      wrapS(GL_REPEAT), wrapT(GL_REPEAT),
      filterMin(GL_LINEAR), filterMax(GL_LINEAR) {
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

Texture2d Texture2d::loadTextureFromFile(const std::string& filename, GLboolean alpha) {
    // Verify the file is there
    std::ifstream input(filename);
    assert(input.is_open());
    input.close();


    Texture2d texture;
    if (alpha) {
        texture.internalFormat = GL_RGBA;
        texture.imageFormat = GL_RGBA;
    }
    int width, height;
    auto imageData = SOIL_load_image(
            filename.c_str(),
            &width, &height, 0,
            texture.imageFormat == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
    auto result = SOIL_last_result();
    texture.generate(width, height, imageData);
    SOIL_free_image_data(imageData);
    return texture;
}