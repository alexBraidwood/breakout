//
// Created by alex on 2/19/17.
//

#ifndef BREAKOUT_TEXTURE2D_H
#define BREAKOUT_TEXTURE2D_H

#include <GL/glew.h>

class Texture2d {
public:
    GLuint id;
    GLuint width, height;
    Gluint internalFormat;
    Gluint imageFormat;

};

#endif //BREAKOUT_TEXTURE2D_H
