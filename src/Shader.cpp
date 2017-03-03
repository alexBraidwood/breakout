/*
 * File: Shader.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Shader.h>
#include <fstream>
#include <cassert>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace graphics;

Shader::Shader()
    : shaderProgram(glCreateProgram()),
      vertexShader(0),
      geometryShader(0),
      fragmentShader(0) { }

const std::string& Shader::getLastShaderError() const {
    return this->lastShaderError;
}

bool Shader::link() {
    glLinkProgram(shaderProgram);

    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteShader(geometryShader);

    int isLinked;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);

    if (isLinked == GL_FALSE) {
        findShaderLinkError(shaderProgram);
    }

    return isLinked == GL_TRUE;
}

bool Shader::loadFragmentShader(const std::string& filename) {
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    auto shaderSource = readFile(filename);
    auto shaderCString = shaderSource.c_str();
    GLint shaderLength = shaderSource.length();

    glShaderSource(fragmentShader, 1, &shaderCString, nullptr);
    glCompileShader(fragmentShader);

    int wasCompiled;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &wasCompiled);

    if (wasCompiled == GL_FALSE) {
        findShaderProgramError(fragmentShader);
        return false;
    }

    glAttachShader(shaderProgram, fragmentShader);
    return true;
}

bool Shader::loadVertexShader(const std::string& filename) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    auto shaderSource = readFile(filename);
    auto shaderCString = shaderSource.c_str();
    GLint shaderLength = shaderSource.length();

    glShaderSource(vertexShader, 1, &shaderCString, nullptr);
    glCompileShader(vertexShader);

    int wasCompiled;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &wasCompiled);

    if (wasCompiled == GL_FALSE) {
        findShaderProgramError(vertexShader);
        return false;
    }

    glAttachShader(shaderProgram, vertexShader);
    return true;
}

bool Shader::loadGeometryShader(const std::string& filename){
    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);

    auto shaderSource = readFile(filename);
    auto shaderCString = shaderSource.c_str();
    GLint shaderLength = shaderSource.length();

    glShaderSource(geometryShader, 1, &shaderCString, nullptr);
    glCompileShader(geometryShader);
    int wasCompiled;
    glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &wasCompiled);

    if (wasCompiled == GL_FALSE) {
        findShaderProgramError(geometryShader);
        return false;
    }

    glAttachShader(shaderProgram, geometryShader);
    glDeleteShader(geometryShader);
    return true;
}

std::string Shader::readFile(const std::string& filename) {
    std::ifstream input(filename);
    std::string result;

    assert(input.is_open());

    input.seekg(0, std::ios::end);
    result.reserve(input.tellg());
    input.seekg(0, std::ios::beg);

    result.assign((std::istreambuf_iterator<char>(input)),
            std::istreambuf_iterator<char>());

    return result;
}

void Shader::findShaderLinkError(GLuint shaderId) {
    int length;
    int maxLength;
    glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
    char* shaderProgramInfoLog = new char[maxLength];

    glGetShaderInfoLog(shaderId, maxLength, &length, shaderProgramInfoLog);

    lastShaderError.assign(shaderProgramInfoLog);
}

void Shader::findShaderProgramError(GLuint shaderId) {
    int length;
    int maxLength;
    glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
    char* shaderProgramInfoLog = new char[maxLength];

    glGetShaderInfoLog(shaderId, maxLength, nullptr, shaderProgramInfoLog);

    lastShaderError.assign(shaderProgramInfoLog);
}

GLuint Shader::id() {
    return shaderProgram;
}

Shader& Shader::use() {
    glUseProgram(this->shaderProgram);
    return *this;
}

void Shader::setFloat(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

void Shader::setInteger(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(this->shaderProgram, name.c_str()), value);
}

void Shader::setVector2f(const std::string& name, const glm::vec2& value) {
    glUniform2f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y);
}

void Shader::setVector3f(const std::string& name, const glm::vec3& value) {
    glUniform3f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z);
}

void Shader::setVector4f(const std::string& name, const glm::vec4& value) {
    glUniform4f(glGetUniformLocation(this->shaderProgram, name.c_str()), value.x, value.y, value.z, value.w);
}

void Shader::setMatrix4(const std::string& name, const glm::mat4& matrix) {
    glUniformMatrix4fv(glGetUniformLocation(this->shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}
