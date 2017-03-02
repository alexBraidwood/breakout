/*
 * File: Resources.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */


#ifndef BREAKOUT_RESOURCES_H
#define BREAKOUT_RESOURCES_H

#include <unordered_map>
#include <string>

#include <GL/glew.h>

#include <Texture2d.h>
#include <Shader.h>
#include <Sprite.h>

namespace core {

class Resources {
public:
    std::unordered_map<std::string, graphics::Shader> shaders;
    std::unordered_map<std::string, graphics::Texture2d> textures;
    std::unordered_map<std::string, graphics::Sprite> sprites;

    Resources() = default;

    /**
     * Loads a shader programs from the provided shader files
     * @param vShaderFile Vertex shader file location
     * @param fShaderFile Fragment shader file location
     * @param gShaderFile Geometry shader file location, leave as empty string if you don't want one
     * @param name Name to associate with shader
     * @return Generated shader program.
     */
    graphics::Shader& loadShader(const std::string& vShaderFile, const std::string& fShaderFile, const std::string& gShaderFile, const std::string& name);
    /**
     * Retrieves a loaded shader
     * @param name Name associated with shader
     * @return Stored shader program
     */
    graphics::Shader& getShader(const std::string& name);
    /**
     * Loads a Texture from the provided file path
     * @param file Location of texture to load
     * @param alpha Whether or not to include alpha channel
     * @param name Name to associate with Texture
     * @return Generated Texture2d
     */
    graphics::Texture2d& loadTexture(const std::string& file, GLboolean alpha, const std::string& name);
    /**
     * Retrieves a loaded Texture
     * @param name Name associated with Texture
     * @return Stored texture
     */
    graphics::Texture2d& getTexture(const std::string& name);
    /**
     * Saves a sprite for this resource batch
     * @param name Name to associate with Sprite
     * @param sprite Sprite to add to resource batch
     */
    void addSprite(graphics::Sprite& sprite, const std::string& name);
    /**
     * Retrieves a sprite from the resource batch
     * @param name Name of Sprite to retrieve
     * @return Sprite with the given name
     */
    graphics::Sprite& getSprite(const std::string& name);
    /**
     * Cleans up and de-allocates resources held by container
     */
    void clear();
};

}

#endif //BREAKOUT_RESOURCES_H
