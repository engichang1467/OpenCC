/*
    Desc: Using glew to get extension

*/

#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main()
{
    if (!glfwInit())
        exit(EXIT_FAILURE);

    int w = 1024, h = 768;
    GLFWwindow *window;
    window = glfwCreateWindow(w, h, "glfw", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    // initialize glew
    glewExperimental = true;  // Helps prevent erros with modern OpenGL
    GLenum glewError = glewInit();

    if (glewError != GLEW_OK)
        printf("glew init error\n%s\n", glewGetErrorString(glewError));

    if ( !GLEW_VERSION_2_1 )
    {
        printf("OpenGL 2.1 not supported!\n");
        return false;
    }

    // Get OpenGL Version String and GLSL Version string
    const GLubyte *p = glGetString(GL_VERSION), *q = glGetString(GL_SHADING_LANGUAGE_VERSION);

    printf("Graphics Driver: %s\n\nGLSL Version: %s\n", p, q);

    // Check for specific functionality
    if (GLEW_ARB_vertex_array_object)
        printf("genVertexArrays supported\n");
    if (GLEW_APPLE_vertex_array_object)
        printf("genVertexArrayAPPLE suported\n");
    

    return 0;
}