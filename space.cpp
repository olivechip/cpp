#include <iostream>     // standard i/o in c++
#include <GL/glew.h>    // manage OpenGL extensions
#include <GLFW/glfw3.h> // window management and input handling

// Declare pointer to a GLFWwindow object
GLFWwindow *window;

// Define error callback function to be called by GLFW if error occurs
void error_callback(int error, const char *description)
{
    (void)error;
    std::cerr << "Error: " << description << std::endl;
}

int main()
{
    // Set the error callback function for GLFW
    glfwSetErrorCallback(error_callback);

    // Initialize GLFW - if failed, return -1
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create window with specified dimensions, title, and monitor settings (NULL for defaults)
    window = glfwCreateWindow(640, 480, "Space Invaders", NULL, NULL);

    // If window creation fails, terminate GLFW and return -1
    if (!window)
    {
        glfwTerminate();
        return -1;

    } // Make the created window the current OpenGL context
    glfwMakeContextCurrent(window);

    // Enable experimental extensions in GLEW
    glewExperimental = GL_TRUE;

    // Initialize GLEW - if failed, print error and return -1
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        return -1;
    }

    // ---------- OpenGL Initialization --------

    // Querying the OpenGL version
    int glVersion[2] = {-1, -1};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
    std::cout << "Using OpenGL: " << glVersion[0] << "." << glVersion[1] << std::endl;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate(); // Terminate GLFW to clean up resources.
    return 0;        // Indicate successful execution of the program.
}