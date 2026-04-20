#ifndef UTILS_H
#define UTILS_H

// #include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Utils
{

public:
    /**
     * @brief Metodo de carga de textura a partir de un arreglo de caracteres 
     * Utiliza SOIL2 
     */
    static GLuint LoadTexture(const char *texImagePath);

    static void MipMapping();
};

#endif