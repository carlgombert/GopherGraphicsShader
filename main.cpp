#include <iostream>
#include <GLFW/glfw3.h>

#include "Reaction.h"

const int WIDTH = 400, HEIGHT = 400;

int start_time = 0;

int main()
{
    auto now = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
    start_time = duration.count();

    std::cout << "part 0" << std::endl;
    glfwInit();

    std::cout << "part 1" << std::endl;

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, WIDTH, HEIGHT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Implement some sort of FPS/update system? right now I think it will render as many frames as fast as possible
    // set this loop to run like 24 times per second
    // maybe implement separate update system for the reaction, that way it can be slowed down/sped up
    std::cout << "part 2" << std::endl;
    Reaction reaction = Reaction(1.0, 1.0, 1.0);
    std::cout << "part 3" << std::endl;
    glViewport(0, 0, WIDTH, HEIGHT);
    while (!glfwWindowShouldClose(window)) {
        auto now = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch());
        int time = duration.count();

        if(time - start_time > 1000/12) {
            start_time = time;
            glClear(GL_COLOR_BUFFER_BIT);

            // Draw in here
            reaction.update();
            reaction.draw();

            glfwSwapBuffers(window);
            glfwPollEvents();
        }
    }

    glfwTerminate();
    return 0;
}
