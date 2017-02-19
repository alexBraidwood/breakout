/*
 * File: Shader.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef GAMEPROJECT_SHADER_H
#define GAMEPROJECT_SHADER_H

#include <string>
#include <GL/glew.h>

namespace graphics {

/**
 * @brief Shader convenience class. Light wrapper around shader functionality.
 */
class Shader {
private:
    GLuint shaderProgram;
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint geometryShader;
    std::string lastShaderError;

    std::string readFile(const std::string& filename);
    const std::string& getLastShaderError() const;
    void findShaderError(GLuint shaderId);

public:
    bool loadVertexShader(const std::string& filename);
    bool loadFragmentShader(const std::string& filename);
    bool loadGeometryShader(const std::string& filename);
    bool link();
    GLuint id();

    Shader() = default;
    ~Shader();
};

}


#endif //GAMEPROJECT_SHADER_H
