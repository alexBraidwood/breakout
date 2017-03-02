/*
 * File: Resources.cpp.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Resources.h>

using namespace core;
using namespace graphics;

Shader& Resources::loadShader(const std::string& vShaderFile, const std::string& fShaderFile,
        const std::string& gShaderFile, const std::string& name) {
    Shader shader;
    shader.loadVertexShader(vShaderFile);
    shader.loadFragmentShader(fShaderFile);
    if (!gShaderFile.empty()) {
        shader.loadGeometryShader(gShaderFile);
    }
    this->shaders.insert(std::make_pair(name, shader));
    return getShader(name);
}

Shader& Resources::getShader(const std::string& name) {
    return shaders.at(name);
}

Texture2d& Resources::loadTexture(const std::string& file, GLboolean alpha, const std::string& name) {
    auto texture = Texture2d::loadTextureFromFile(file, alpha);
    textures.insert(std::make_pair(name, texture));
    return getTexture(name);
}

Texture2d& Resources::getTexture(const std::string& name) {
    return textures.at(name);
}

Sprite& Resources::getSprite(const std::string& name) {
    return sprites.at(name);
}

void Resources::addSprite(graphics::Sprite& sprite, const std::string& name) {
    sprites.insert(std::make_pair(name, sprite));
}

void Resources::clear() {
    for (auto shaderPair : shaders) {
        glDeleteProgram(shaderPair.second.id());
    }
    for (auto texturePair : textures) {
        glDeleteTextures(1, &texturePair.second.id);
    }
}
