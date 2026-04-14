#ifndef SCENE_H 
#define SCENE_H

#include <GL/glew.h>  
#include <GLFW/glfw3.h> 
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include "WindowGL.h"
#include "ShaderProgram.h"

#include "Model.h"
#include "models/Cube.h"
#include "models/CustomModel.h"

#include "Camera.h" // << NUEVO 

#include "linear_math/Matrix4D.h"
#include "linear_math/Vector3D.h"


/**
 * @class Scene
 * @brief Clase para modelar una escena que contiene una ventana, un shaderprogram y un modelo 
 */
class Scene
{
private:

    WindowGL* m_window; 
    ShaderProgram*  m_shaderProgram; // This could be a std::vector of shader programs 
    Model* m_model; // This could be a std::vector of Models 
    
    Camera* m_camera; 

    // linear::math::Vector3D m_camera_pos; 

    // linear::math::Matrix4D m_view; 
    // linear::math::Matrix4D m_projection; 

    /**
     * @brief Inicializacion 
     */
    void init();

public:

    Scene(){
        init();
    }

    ~Scene(){
        delete m_window;
        delete m_shaderProgram;
        delete m_camera; 
    }

    /**
     * @brief Ciclo de renderizado general 
     */
    void render(); 

};



#endif