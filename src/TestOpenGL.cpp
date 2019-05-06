//============================================================================
// Name        : TestOpenGL.cpp
// Author      : Tim White
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "ShaderHandler.h"
#include "IdGroup.h"
#include "TextureObject.h"

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"





const int LOCAL_WINDOW_WIDTH   =   1920;
const int LOCAL_WINDOW_HEIGHT  =   1080;



// called each time the window is resized and adjusts the glViewport accordingly
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// processes all user input
void processInput(GLFWwindow * window){

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){

        glfwSetWindowShouldClose(window, true);

    }
}

int main(){

    // initialising glfw, defining opengl versions and telling glfw that opengl is going to be used
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /*
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    */

    // Creating OpenGL window

    GLFWwindow *window = glfwCreateWindow(LOCAL_WINDOW_WIDTH, LOCAL_WINDOW_HEIGHT, "Hello World", NULL, NULL);

    // Check the process of inialising the window was successfull

    if(window == NULL){

        std::cout << "Error creating new GLFW window, are all dependancies available? " << std::endl;
        return -1;
    }

    // Set the OpenGL context
    glfwMakeContextCurrent(window);


    glViewport(0, 0, LOCAL_WINDOW_WIDTH, LOCAL_WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Initialise GLEW
    GLenum error = glewInit();

    // If GLEW failed to intialise termintate and print error message
    if(error != GLEW_OK){

        std::cout<< "ERROR::GLEW::INIT::FAILED\n" << glewGetErrorString(error) << std::endl;

        glfwTerminate();
        return -1;
    }



    // Create and Compile a Simple Vertex Shader (vertex shaders define how vertex data should be mapped into the rendering context)
    // Vertex shaders are compiled during runtime. The source code for this VERY simple vertex shader is defined in the constant C string above.
    // Vertex Shaders are written in GLSL. (GL Shading Language)

    Shader *vertexShader = new Shader("resources/shaders/vertexShaderDefault.vert", GL_VERTEX_SHADER);


    // Creating and Compiling a Simple Fragment Shader (fragment shaders define how individual pixels on the screen will be given colour values)
    // Fragment shaders are also compiled during runtime. The source code for this VERY simple fragment shader is defined in the constant C string above.
    // Fragment Shaders are also written in GLSL.

    Shader *fragmentShader = new Shader("resources/shaders/fragmentShaderDefault.frag", GL_FRAGMENT_SHADER);
    // create the actual shader program

    ShaderHandler *shaderProgram = new ShaderHandler(vertexShader, fragmentShader);

    shaderProgram->compile();

    // Vertex Definitions

    float vertices[] = {
     0.5f,  0.5f, 0.0f,		0.0f,  1.0f,  0.0f,		1.0f,  1.0f,	// top right
     0.5f, -0.5f, 0.0f,		1.0f,  0.0f,  0.0f,		1.0f,  0.0f,	// bottom right
    -0.5f, -0.5f, 0.0f,  	0.0f,  1.0f,  0.0f,		0.0f,  0.0f,	// bottom left
    -0.5f,  0.5f, 0.0f,   	0.0f,  0.0f,  1.0f,		0.0f,  1.0f		// top left
    };

    unsigned int indices[] = {
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };

    glm::mat4x4 trans = glm::mat4x4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.3f, 0.3f, 0.0f));


    // GL Buffer Creation and Binding (this is where vertex data is stored on the GPU)

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int EBO;
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // Binding VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


    // Binding EBO (EBO's use indexes to draw rather than raw vertex data, this allows gpu memory to be saved by approx 1/3)

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    // Linking vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3 * sizeof(float)));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6 * sizeof(float)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


	// Loading a Texture

    IdGroup * textureIds = new IdGroup(0);

    TextureObject * texture = new TextureObject("resources/textures/crate.png", textureIds);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    while(!glfwWindowShouldClose(window)){

        processInput(window);

        // Render info should go here
        glBindVertexArray(0);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        texture->useTexture();

        shaderProgram->use();
        shaderProgram->setFloat4x4m("transform", trans);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        trans = glm::rotate(trans, (float)(glfwGetTime() * 0.001), glm::vec3(0.0f, 0.0f, 1.0f));


        glfwSwapBuffers(window);
        glfwPollEvents();


    }

    glfwTerminate();

    return 0;
}
