/*
 * File: Texture2d.h.
 * Created by: Alex Braidwood.
 * Date: Feb 19, 2017.
 * Notice: Copyright (c) 2017 The Bat Forge. All Rights Reserved.
 */

#ifndef BREAKOUT_TEXTURE2D_H
#define BREAKOUT_TEXTURE2D_H

#include <GL/glew.h>
#include <string>

namespace graphics {

class Texture2d {
public:
    GLuint id;
    GLuint width, height;
    GLuint internalFormat;
    GLuint imageFormat;
    /**
     * @brief Wrapping mode on the S-axis
     */
    GLuint wrapS;
    /**
     * @brief Wrapping mode on the T-axis
     */
    GLuint wrapT;
    /**
     * @brief Filtering mode if texture pixels < screen pixels
     */
    GLuint filterMin;
    /**
     * @brief Filtering mode if texture pixels > screen pixels
     */
    GLuint filterMax;

    Texture2d();

    void generate(GLuint width, GLuint height, unsigned char* data);

    void bind() const;

    static Texture2d loadTextureFromFile(const std::string& filename, GLboolean alpha);
};

}

#endif //BREAKOUT_TEXTURE2D_H
