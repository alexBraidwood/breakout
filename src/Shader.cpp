/*
 * File: Shader.cpp.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#include <Shader.h>
#include <fstream>
#include <cassert>

using namespace graphics;

const std::string& Shader::getLastShaderError() const {
    return this->lastShaderError;
}

bool Shader::link() {
    glLinkProgram(shaderProgram);

    int isLinked = 0;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &isLinked);

    if (isLinked == GL_FALSE) {
        findShaderError(shaderProgram);
    }

    return isLinked = GL_TRUE;
}

bool Shader::loadFragmentShader(const std::string& filename) {
    GLuint shader;
    shader = glCreateShader(GL_FRAGMENT_SHADER);

    auto shaderSource = readFile(filename);
    auto shaderCString = shaderSource.c_str();
    GLint shaderLength = shaderSource.length();

    glShaderSource(shader, 1, &shaderCString, &shaderLength);
    glCompileShader(shader);

    int wasCompiled = GL_FALSE;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &wasCompiled);

    if (wasCompiled == GL_FALSE) {
        findShaderError(fragmentShader);
        return false;
    }

    glAttachShader(shaderProgram, fragmentShader);
    return true;
}

bool Shader::loadVertexShader(const std::string& filename) {
    GLuint shader;
    shader = glCreateShader(GL_VERTEX_SHADER);

    auto shaderSource = readFile(filename);
    auto shaderCString = shaderSource.c_str();
    GLint shaderLength = shaderSource.length();

    glShaderSource(shader, 1, &shaderCString, &shaderLength);
    glCompileShader(shader);

    int wasCompiled = GL_FALSE;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &wasCompiled);

    if (wasCompiled == GL_FALSE) {
        findShaderError(vertexShader);
        return false;
    }

    glAttachShader(shaderProgram, vertexShader);
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

void Shader::findShaderError(GLuint shaderId) {
    int maxLength;
    glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

    auto shaderProgramInfoLog = new char[maxLength];
    glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);

    lastShaderError.assign(shaderProgramInfoLog);

    delete shaderProgramInfoLog;
}

GLuint Shader::id() {
    return shaderProgram;
}

Shader::~Shader() {
    glUseProgram(0);
    glDetachShader(shaderProgram, vertexShader);
    glDetachShader(shaderProgram, fragmentShader);

    glDeleteProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}
