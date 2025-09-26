cmake_minimum_required(VERSION 3.24)

project(mathematical_fundations)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(${PROJECT_NAME}
    glfw
    GLEW
    GL 
)

