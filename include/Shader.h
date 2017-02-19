//
// Created by Maddog on 7/31/2016.
//

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
    std::string lastShaderError;

    std::string readFile(const std::string& filename);
    const std::string& getLastShaderError() const;
    void findShaderError(GLuint shaderId);

public:
    bool loadVertexShader(const std::string& filename);
    bool loadFragmentShader(const std::string& filename);
    bool link();
    GLuint id();

    Shader() = default;
    ~Shader();
};

}


#endif //GAMEPROJECT_SHADER_H
