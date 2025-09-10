#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

//  Dibujar dos cuadrados de distinto color 


#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
const char *fragmentShaderSourcePurple = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.6f, 0.0f, 0.6f, 1.0f);\n"
    "}\n\0";

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialize GLEW
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // fragment shader
    unsigned int fragmentShaderPurp = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderPurp, 1, &fragmentShaderSourcePurple, NULL);
    glCompileShader(fragmentShaderPurp);
    // check for shader compile errors
    glGetShaderiv(fragmentShaderPurp, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderPurp, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders
    unsigned int shaderProgram = glCreateProgram();

    // Shader program 2 
    unsigned int shaderProgramPurp = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glAttachShader(shaderProgramPurp,vertexShader);
    glAttachShader(shaderProgramPurp,fragmentShaderPurp);
    glLinkProgram(shaderProgramPurp);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glGetProgramiv(shaderProgramPurp, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgramPurp, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(fragmentShaderPurp);

    //Excercise 2 squares 
    // Square 1 
    float vertices_sqr_1[] = { //vertex 
        0.5f, 0.0f, 0.0f, // bottom right  
        0.5f, 0.5f, 0.0f, // top right 
        0.0f,  0.5f, 0.0f,  // top left    
        0.0f,  0.0f, 0.0f  // bottom left    
    }; 

    // indices 
    unsigned int indices_sqr_1[]={
        0,1,2,
        0,2,3
    };

    //Square 2 
    float vertices_sqr_2[] = { //vertex 
        0.0f, 0.0f, 0.0f, // bottom right  
        0.0f, -0.5f, 0.0f, // top right 
        -0.5f, -0.5f, 0.0f,  // top left    
        -0.5f,  0.0f, 0.0f  // bottom left    
    }; 

    // indices 
    unsigned int indices_sqr_2[]={
        0,1,2,
        0,2,3
    };

    GLuint VBO_sqr_1, VAO_sqr_1; 
    GLuint VBO_sqr_2, VAO_sqr_2;
    GLuint EBO_sqr_1, EBO_sqr_2;  

    //Generacion IDs 
    glGenVertexArrays(1, &VAO_sqr_1);
    glGenVertexArrays(1, &VAO_sqr_2);

    glGenBuffers(1, &VBO_sqr_1);
    glGenBuffers(1, &VBO_sqr_2);

    glGenBuffers(1,&EBO_sqr_1);
    glGenBuffers(1,&EBO_sqr_2);
    
    // SQUARE 1 
    glBindVertexArray(VAO_sqr_1);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO_sqr_1);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_sqr_1), vertices_sqr_1, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_sqr_1);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_sqr_1), indices_sqr_1, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    // SQUARE 1 

    glBindVertexArray(VAO_sqr_2);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO_sqr_2);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_sqr_2), vertices_sqr_2, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO_sqr_2);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_sqr_2), indices_sqr_2, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
     
    
    glBindVertexArray(0); 
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        //glUseProgram(shaderProgramPurp);
        glBindVertexArray(VAO_sqr_1); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glUseProgram(shaderProgramPurp);
        glBindVertexArray(VAO_sqr_2);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO_sqr_1);
    glDeleteBuffers(1, &VBO_sqr_1);
    glDeleteBuffers(1, &EBO_sqr_1);

    glDeleteVertexArrays(1, &VAO_sqr_2);
    glDeleteBuffers(1, &VBO_sqr_2);
    glDeleteBuffers(1, &EBO_sqr_2);

    glDeleteProgram(shaderProgram);
    glDeleteProgram(shaderProgramPurp);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}