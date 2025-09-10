cmake_minimum_required(VERSION 3.24)

project(opengl_hello_triangle)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/Main.cpp)

target_link_libraries(${PROJECT_NAME}
    glfw
    GLEW
    GL 
)
