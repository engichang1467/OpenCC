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

    printf("Hello Window\n");

    while ( !glfwWindowShouldClose(window))
    {
        glViewport(0,0,w,h);
        glClearColor(1,0,0,1);          // choose the color we want to output
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents(); // Listen for window events
    }

    // Destroy window and terminate glfw
    glfwDestroyWindow(window);
    glfwPollEvents();
    printf("goodbye window\n");

    return 0;
}