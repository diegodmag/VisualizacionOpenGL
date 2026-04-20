#version 430 core
in vec2 tc; // Recibida desde el vertex shader

layout (binding = 0) uniform sampler2D samp;

out vec4 FragColor;

void main()
{
    // Muestreamos la textura usando las coordenadas tc
    // y asignamos el resultado directamente al color de salida
    
    // FragColor = vec4(tc, 0.0, 1.0);
    FragColor = texture(samp, tc);
}