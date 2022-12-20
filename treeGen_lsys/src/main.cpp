#include "lsys.h"
#include <unistd.h>


int main()
{
    const int levels = 4;
    // cout<<"1";

    if (!glfwInit())    // This function initializes the GLFW library. 
        return 1;

    GLFWwindow* window = glfwCreateWindow(1000, 1000, "New Window", NULL, NULL);


    glfwMakeContextCurrent(window);
    glOrtho(0, 1000, 0, 1000, -5, 5);
    // cout<<"2";

    lsys l(1, "X");

    while (!glfwWindowShouldClose(window)) {
            // cout<<"3";
        sleep(1); 
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         
        if (l.depth1 < levels) {
            l.depth1 = l.depth1 + 1;
            l.create_sequence("X", l.depth1, 0);
            // cout<<l.genStr; 
        }
        
        // cout<<l.genStr;

        l.visualise_sequence(l.genStr);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // cout<<"6";

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
