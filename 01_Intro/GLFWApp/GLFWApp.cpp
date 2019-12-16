/*
    Desc: glfw window app

    Author: Michael Chang
*/

#include "../../include/glfw_app.hpp"

using namespace lynda;

struct MyApp : App {
    MyApp() : App() {}

    virtual void onDraw(){
    }

    virtual void onMouseMove(int x, int y)
    {
        printf("%d %d\n", x, y);
    }
    virtual void onMouseDown(int button, int action)
    {
        if (action == GLFW_PRESS)
            printf("mouse pressed\n");
        if (action == GLFW_RELEASE)
            printf("mouse released\n");
    }
    virtual void onKeyDown(int key, int action) 
    {
        printf("%u\n", (unsigned char)key);
    }
};

int main(){

  MyApp app;
  app.start();
  
  printf("goodbye window\n");

  return 0;
}