#include "Scene.h"
#include "MathUtils.h"

void Scene::init(){
    //Inicializacion de ventana 
    m_window = new WindowGL();
    //Inicializacion de ProgramShader 
    m_shaderProgram = new ShaderProgram("shaders/vertex_shader.glsl","shaders/frag_shader.glsl");
    //Inicializacion del Modelo -> Cubo 
    m_model = new Cube(m_shaderProgram);
    //Matriz de vista View Matrix
    // Create view matrix using custom lookAt
    linear::math::Vector3D eye(-2.0f, 3.0f, -5.0f);
    linear::math::Vector3D center(0.0f, 0.0f, 0.0f);
    linear::math::Vector3D up(0.0f, 1.0f, 0.0f);
    m_view = linear::math::Matrix4D::lookAt(eye, center, up);
        
    // Create projection matrix using custom perspective
    m_projection = linear::math::Matrix4D::perspective(
        linear::math::radians(45.0f),  // You can use your own radians function
        m_window->getAspectRation(),
        0.1f, 
        100.0f
    );
}

// void Scene::render() const {

//     //Ciclo de Renderizado

//     while(!glfwWindowShouldClose(m_window->getWindow())){

//         // Compute time  

//         if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
//             glfwSetWindowShouldClose(m_window->getWindow(), true);

//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
//         m_model->renderModel(m_view, m_projection);

//         glfwSwapBuffers(m_window->getWindow());
        
//         glfwPollEvents();

//         // update models 
//     }

// }

void Scene::render() const {
    while(!glfwWindowShouldClose(m_window->getWindow())) {
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_window->getWindow(), true);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // The cube will use its identity matrix (no rotation/translation)
        m_model->renderModel(m_view, m_projection);

        glfwSwapBuffers(m_window->getWindow());
        glfwPollEvents();
    }
}