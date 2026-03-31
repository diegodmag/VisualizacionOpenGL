#include "Scene.h"
#include "MathUtils.h"

void Scene::init(){

    m_window = new WindowGL();

    m_shaderProgram = new ShaderProgram("shaders/vertex_shader.glsl","shaders/frag_shader.glsl");

    m_model = new Cube(m_shaderProgram);


    
    // View matrix usando lookAt
    m_camera_pos = linear::math::Vector3D(-2.0f, 3.0f, -5.0f);
    linear::math::Vector3D center(0.0f, 0.0f, 0.0f);
    linear::math::Vector3D up(0.0f, 1.0f, 0.0f);
    m_view = linear::math::Matrix4D::lookAt(m_camera_pos, center, up);
        
    // Create projection matrix using custom perspective
    m_projection = linear::math::Matrix4D::perspective(
        linear::math::radians(45.0f), 
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

// void Scene::render() const {
//     while(!glfwWindowShouldClose(m_window->getWindow())) {
//         if (glfwGetKey(m_window->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
//             glfwSetWindowShouldClose(m_window->getWindow(), true);

//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
//         // The cube will use its identity matrix (no rotation/translation)
//         m_model->renderModel(m_view, m_projection);

//         glfwSwapBuffers(m_window->getWindow());
//         glfwPollEvents();
//     }
// }
void Scene::render() { // Sin const
    while(!glfwWindowShouldClose(m_window->getWindow())) {
        
        // --- INPUT SIMPLE ---
        float speed = 0.01f;

        // Mover en el eje Z (Adelante/Atrás)
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
            m_camera_pos.z += speed;
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
            m_camera_pos.z -= speed;

        // Mover en el eje X (Izquierda/Derecha)
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
            m_camera_pos.x -= speed;
        if (glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
            m_camera_pos.x += speed;

        // --- ACTUALIZAR MATRIZ ---
        // Usamos m_camera_pos como el "eye" y (0,0,0) como el centro a donde mira
        m_view = linear::math::Matrix4D::lookAt(
            m_camera_pos, 
            linear::math::Vector3D(0.0f, 0.0f, 0.0f), 
            linear::math::Vector3D(0.0f, 1.0f, 0.0f)
        );

        // --- DIBUJAR ---
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_model->renderModel(m_view, m_projection);

        glfwSwapBuffers(m_window->getWindow());
        glfwPollEvents();
    }
}