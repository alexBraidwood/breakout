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

namespace core {

class Resources {
public:
    std::unordered_map<std::string, Shader> shaders;
    std::unordered_map<std::string, Texture2d> textures;

    Resources() = default;

    /**
     * Loads a shader programs from the provided shader files
     * @param vShaderFile - Vertex shader file location
     * @param fShaderFile - Fragment shader file location
     * @param gShaderFile - Geometry shader file location, leave as empty string if you don't want one
     * @param name - Name to associate with shader
     * @return Generated shader program.
     */
    Shader& loadShader(const std::string& vShaderFile, const std::string& fShaderFile, const std::string& gShaderFile, const std::string& name);
    /**
     * Retrieves a loaded shader
     * @param name - Name associated with shader
     * @return Stored shader program
     */
    Shader& getShader(const std::string& name);
    /**
     * Loads a Texture from the provided file path
     * @param file - Location of texture to load
     * @param alpha - Alpha channel (0 to 255)
     * @param name - Name to associate with Texture
     * @return Generated Texture2d
     */
    Texture2d& loadTexture(const std::string& file, GLboolean alpha, const std::string& name);
    /**
     * Retrieves a loaded Texture
     * @param name - Name associated with Texture
     * @return Stored texture
     */
    Texture2d& getTexture(const std::string& name);
    /**
     * Cleans up and de-allocates resources held by container
     */
    void clear();
};

}

#endif //BREAKOUT_RESOURCES_H
