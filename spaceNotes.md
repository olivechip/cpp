OpenGL is the library for graphics output. It handles all the drawing, rendering, and visual effects.

GLFW is the library for window management and input, providing the environment and interaction tools that OpenGL needs.

GLFWerrorfun glfwSetErrorCallback(GLFWerrorfun cbfun);
- the standard in setting error callbacks in GLFW


Compiling the Code
- spent lots of time figuring out where the library was located...

g++ -std=c++17 -o space space.cpp -I"/usr/include/GL" -I"/usr/include/GLFW" -L"/usr/lib/x86_64-linux-gnu" -lglfw -lGLEW -lGL