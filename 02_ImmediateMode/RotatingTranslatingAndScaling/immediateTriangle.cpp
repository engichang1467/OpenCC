#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

int width, height;

void drawTriangle()
{
    // Draw triangle
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-1,-1,0);
        glColor3f(0,1,0);
        glVertex3f(0,1,0);
        glColor3f(0,0,1);
        glVertex3f(1,-1,0);
    glEnd();
}

void draw()
{
    static float counter = 0.0;
    counter += .01;

    // Transform The orthogonal Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(float)width/height, (float)width/height, -1.f, 1.f, 1.f, -1.f);

    // Transform ModelView Matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw 10 triangles
    for (int i = 0; i < 10; ++i)
    {
        float t = (float)i/10;
        glPushMatrix();

         // scale, then rotate, then Translate
         glTranslatef(t * sin(counter), 0, 0);
         glRotatef(360 * t * counter, 0, 0, 1);
         glScalef(1-t, 1-t, 1-t);

         drawTriangle();

         glPopMatrix();
    }

}

int main()
{
    printf("Hello Triangle\n");
    if( !glfwInit() ) 
        exit(EXIT_FAILURE);
    
    width = 640; height = 480;
    
    GLFWwindow * window;       //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
    window = glfwCreateWindow(width, height, "glfw", NULL, NULL);
    
    
    if (!window) {                   //Check Validity
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);  //Make Window Current Context

    glfwSwapInterval(1);
    
  
    /*-----------------------------------------------------------------------------
     *  MAIN LOOP
     *-----------------------------------------------------------------------------*/
    while ( !glfwWindowShouldClose(window) ){
        
        //Set view port size and position every frame of animation
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0,0,width,height); // move here to update the viewport on every frame in case of resizing the window 
        glClearColor(.2,.2,.2,1);                  //<-- CLEAR WINDOW CONTENTS
        glClear( GL_COLOR_BUFFER_BIT );
        
        //put drawing code in here
        draw();
        
        glfwSwapBuffers(window);                //<-- SWAP BUFFERS
        glfwPollEvents();                       //<-- LISTEN FOR WINDOW EVENTS
    }

    //properly destroy window and terminate glfw
    glfwDestroyWindow(window);
    glfwTerminate();
    
    printf("goodbye triangle\n");
    
    return 0;
}