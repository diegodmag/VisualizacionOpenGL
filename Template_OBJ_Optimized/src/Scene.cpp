#include "Scene.h"
#include "MathUtils.h"

void Scene::init()
{

    m_window = new WindowGL();

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS); // Los objetos más cercanos tapan a los lejanos

    m_shaderProgram = new ShaderProgram("shaders/vert_text_shader.glsl", "shaders/frag_text_shader.glsl");

    m_model = new CustomModel(m_shaderProgram, "assets/obj/beagle.obj", "assets/textures/beagle.jpg");

    m_camera_pos = linear::math::Vector3D(0.0f, 10.0f, -10.0f);

    linear::math::Vector3D center(0.0f, 0.0f, 0.0f);
    linear::math::Vector3D up(0.0f, 1.0f, 0.0f);
    m_view = linear::math::Matrix4D::lookAt(m_camera_pos, center, up);

    m_projection = linear::math::Matrix4D::perspective(
        linear::math::radians(45.0f),
        m_window->getAspectRation(),
        0.1f,
        100.0f);
}

void Scene::render()
{

    float lastFrame = 0.0f;
    m_model->translate(linear::math::Vector3D(0.0f, 0.0f, -2.0f));
    m_model->rotate(90.0f, linear::math::Vector3D(1.0f, 0.0f, 0.0f));
    m_model->scale(linear::math::Vector3D(0.1f, 0.1f, 0.1f));

    while (!glfwWindowShouldClose(m_window->getWindow()))
    {

        float currentFrame = static_cast<float>(glfwGetTime());
        float deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        float speed = 0.01f;

        m_model->rotate(45.0f * deltaTime, linear::math::Vector3D(0.0f, 0.0f, 1.0f));

        m_view = linear::math::Matrix4D::lookAt(
            m_camera_pos,
            linear::math::Vector3D(0.0f, 0.0f, 0.0f),
            linear::math::Vector3D(0.0f, 1.0f, 0.0f));

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_model->renderModel(m_view, m_projection);

        glfwSwapBuffers(m_window->getWindow());
        glfwPollEvents();
    }
}