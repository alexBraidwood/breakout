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
#include <glm/glm.hpp>

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
    Shader& use();
    GLuint id();

    void setFloat(const std::string& name, float value);
    void setInteger(const std::string& name, int value);
    void setVector2f(const std::string& name, const glm::vec2& value);
    void setVector3f(const std::string& name, const glm::vec3& value);
    void setVector4f(const std::string& name, const glm::vec4& value);
    void setMatrix4(const std::string& name, const glm::mat4& matrix);

    Shader() = default;
    ~Shader();
};

}


#endif //GAMEPROJECT_SHADER_H
