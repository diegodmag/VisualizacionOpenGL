#include "Scene.h"
#include "MathUtils.h"


void Scene::init(){

    m_window = new WindowGL();

    m_shaderProgram = new ShaderProgram("shaders/vertex_shader.glsl","shaders/frag_shader.glsl");

    m_model = new CustomModel(m_shaderProgram,"assets/obj/Teapot.obj");


    // Camera settings 

    m_camera = new Camera{linear::math::Vector3D(-2.0f, 3.0f, -5.0f)}; // NUEVO

    m_camera->InitPerspectiveFrustrum(linear::math::radians(45.0f), 
                                      m_window->getAspectRation(),
                                      0.1f,
                                      100.f);
    m_camera->ComputeView();  
    m_camera->ComputeProjection(); 


    // For mouse callback 
    glfwSetWindowUserPointer(m_window->getWindow(), this);

    glfwSetCursorPos(m_window->getWindow(), m_window->getWidth()/2, m_window->getHeight()/2);


    glfwSetCursorPosCallback(m_window->getWindow(), [](GLFWwindow* window, double xpos, double ypos) {
        // Recuperamos el puntero de la escena
        Scene* scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));
        if (scene) {
            scene->m_camera->ComputeRotation(xpos, ypos);
        }
    });
}


void Scene::process_input(float deltaTime){

    float cameraSpeed = static_cast<float>(2.5 * deltaTime);
    
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
        m_camera->Move_Foreward(-cameraSpeed);
        // std::cout<<"W\n"; 
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
        m_camera->Move_Foreward(cameraSpeed);
        // std::cout<<"S\n"; 
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
        m_camera->Move_Right(cameraSpeed);
        // std::cout<<"D\n";         
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
        m_camera->Move_Right(-cameraSpeed);
        // std::cout<<"A\n"; 
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_E) == GLFW_PRESS)
        m_camera->Move_Up(cameraSpeed);
        // std::cout<<"E\n"; 
    if (glfwGetKey(m_window->getWindow(), GLFW_KEY_Q) == GLFW_PRESS)
        m_camera->Move_Up(-cameraSpeed);
        // std::cout<<"Q\n"; 

    // Es necesario volver a calcular la matriz de vista 
    m_camera->ComputeView(); // 
}

void Scene::render() { // Sin const

    m_model->translate(linear::math::Vector3D(-2.0f,1.5f,2.0f)); 
    // m_model->translate(linear::math::Vector3D(0.0f,-1.5f,0.0f)); 
    

    float lastFrame = 0.0f; // Tiempo transcurrido del frame anterior 

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    while(!glfwWindowShouldClose(m_window->getWindow())) {
        
        float currentFrame = static_cast<float>(glfwGetTime()); // Obtiene el tiempo desde que inicio la aplicacion 
        float deltaTime = currentFrame-lastFrame; 
        lastFrame = currentFrame; 

        float speed = 0.01f;

        // --- DIBUJAR ---
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // m_model->renderModel(m_view, m_projection);
        m_model->renderModel(m_camera->getView(), m_camera->getProjection());

        glfwSwapBuffers(m_window->getWindow());
        glfwPollEvents();

        process_input(deltaTime);
    }
}