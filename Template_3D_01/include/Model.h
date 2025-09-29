#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>  
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ShaderProgram.h"

/**
 * @class Model
 * @brief Modelo para ser derivado a distintas figuras/mallas 
 */
class Model{

protected:

    ShaderProgram* m_shaderProgram;
    GLuint VAO, VBO, EBO; 
    glm::mat4 m_model_mat;
    // float angle 

    /**
     * @brief Inicializa vertices  
     */
    virtual void initGeometry() = 0; // Debe ser implementada por una derivada
    
    /**
     * @brief Inicializa buffers 
     */
    virtual void init() = 0; // Debe ser implementada por una derivada


public: 

    Model(ShaderProgram* program)
        : m_shaderProgram{program}
        , VAO(0)
        , VBO(0)
        , EBO(0)
        , m_model_mat(1.0f)
    {

    }

    ~Model(){
        delete m_shaderProgram;
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }

    /**
     * @brief Utiliza el ShaderProgram para renderizar el modelo a partir de las matrices de projection y de vista
     * @param view Matriz de vista 
     * @param projection Matriz de proyeccion 
     */
    virtual void renderModel(const glm::mat4& view, const glm::mat4& projection) = 0;

    /**
     * @brief Aplica transformaciones o animaciones 
     * @param deltaTime Referencia del tiempo transcurrido entre frames  
     */
    virtual void updateModel(float deltaTime) = 0;

    /**
     * @brief Limpia recursos 
     */
    virtual void finish() = 0;

};

#endif