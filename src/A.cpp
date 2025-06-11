#include "A.hpp"
#include <iostream>
#include <thread>
#include <GLFW/glfw3.h>

A::A(const std::vector<std::shared_ptr<Ability>>& abilities) : abilities(abilities) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        std::exit(EXIT_FAILURE);
    }
}

A::~A() {glfwTerminate();}

void A::run() {
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Agent A", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    std::vector<std::thread> threads;
    for (const auto& ability : abilities) {
        threads.emplace_back([ability]() {
            try {
                ability->run();
            } catch (const std::exception& e) {
                std::cerr << "Error in ability: " << e.what() << std::endl;
            }
        });
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }

    glfwDestroyWindow(window);
}
