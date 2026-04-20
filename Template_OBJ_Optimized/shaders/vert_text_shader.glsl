#version 430 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec2 tc; // Enviamos a tc al fragment shader

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0);
    
    // Pasamos la coordenada de textura directamente
    tc = texCoord;
}