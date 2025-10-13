#ifndef WINDOWGL_H
#define WINDOWGL_H

#include <iostream>
#include <GL/glew.h> //Manejo de ventanas e input 
#include <GLFW/glfw3.h> //

/**
 * @class WindowGL
 * @brief Clase que modela una ventana de OpenGL junto con inicializacion de GLEW y GLFW
 */
class WindowGL
{

private: 

    GLFWwindow* m_window; 
    char * m_name; 
    int m_glfwMajor{};
    int m_glfwMinor{};
    int m_width{}, m_height{};

public: 

    WindowGL(char * name=(char*)"OpenGL Window", int major=4, int minor=3, int width=1280 , int height=720)
            : m_name{name}
            , m_glfwMajor{major}
            , m_glfwMinor{minor}
            , m_width{width}
            , m_height{height}{
                InitGLFW();
                InitGLEW();
            }
            
    ~WindowGL(){
        if(m_window){glfwDestroyWindow(m_window);}
        glfwTerminate();
    }

    GLFWwindow* getWindow() const {return m_window;}

    float getAspectRation() const {return static_cast<float>(m_width)/static_cast<float>(m_height);}

    /**
     * @brief Inicializa la biblioteca GLFW y la ventana m_window
     */
    void InitGLFW();

    /**
     * @brief Inicializa la biblioteca GLEW
     */
    void InitGLEW();

};


#endif