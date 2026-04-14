#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>  
#include <GLFW/glfw3.h>
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

#include "ShaderProgram.h"

#include "linear_math/Matrix4D.h"
#include "linear_math/Vector3D.h"
#include "MathUtils.h"

/**
 * @class Model
 * @brief Modelo para ser derivado a distintas figuras/mallas 
 */
class Model{

protected:

    ShaderProgram* m_shaderProgram;
    GLuint VAO, VBO, EBO; 

    linear::math::Matrix4D m_model_mat; 
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
    {
        m_model_mat = linear::math::Matrix4D::identity();
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
    virtual void renderModel(const linear::math::Matrix4D& view, const linear::math::Matrix4D& projection) = 0;
    
    virtual void translate(const linear::math::Vector3D& translation) = 0; 

    virtual void rotate(float angle, const linear::math::Vector3D& axis) = 0; 

    virtual void scale(const linear::math::Vector3D& scaling) = 0; 

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