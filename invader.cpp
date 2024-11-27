#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GL_ERROR_CASE(glerror) \
    case glerror:              \
        return #glerror

constexpr const char *get_gl_error_string(GLenum err)
{
    switch (err)
    {
        GL_ERROR_CASE(GL_INVALID_ENUM);
        GL_ERROR_CASE(GL_INVALID_VALUE);
        GL_ERROR_CASE(GL_INVALID_OPERATION);
        GL_ERROR_CASE(GL_INVALID_FRAMEBUFFER_OPERATION);
        GL_ERROR_CASE(GL_OUT_OF_MEMORY);
    default:
        return "UNKNOWN_ERROR";
    }
}

inline void gl_debug(const char *file, int line)
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        std::cerr << "OpenGL Error (" << get_gl_error_string(err)
                  << ") at " << file << ":" << line << "\n";
    }
}

void validate_shader(GLuint shader, const char *file = nullptr)
{
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char buffer[512];
        glGetShaderInfoLog(shader, sizeof(buffer), nullptr, buffer);
        std::cerr << "Shader compile error in " << (file ? file : "Unknown")
                  << ": " << buffer << "\n";
    }
}

bool validate_program(GLuint program)
{
    GLint success = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        char buffer[512];
        glGetProgramInfoLog(program, sizeof(buffer), nullptr, buffer);
        std::cerr << "Program link error: " << buffer << "\n";
        return false;
    }
    return true;
}

void error_callback(int error, const char *description)
{
    std::cerr << "GLFW Error [" << error << "]: " << description << "\n";
}

struct Buffer
{
    size_t width, height;
    std::vector<uint32_t> data;
};

struct Sprite
{
    size_t width, height;
    std::vector<uint8_t> data;
};

void buffer_clear(Buffer &buffer, uint32_t color)
{
    std::fill(buffer.data.begin(), buffer.data.end(), color);
}

bool sprite_overlap_check(
    const Sprite &sp_a, size_t x_a, size_t y_a,
    const Sprite &sp_b, size_t x_b, size_t y_b)
{
    return (x_a < x_b + sp_b.width && x_a + sp_a.width > x_b &&
            y_a < y_b + sp_b.height && y_a + sp_a.height > y_b);
}

void buffer_draw_sprite(Buffer &buffer, const Sprite &sprite, size_t x, size_t y, uint32_t color)
{
    for (size_t xi = 0; xi < sprite.width; ++xi)
    {
        for (size_t yi = 0; yi < sprite.height; ++yi)
        {
            if (sprite.data[yi * sprite.width + xi] &&
                (sprite.height - 1 + y - yi) < buffer.height &&
                (x + xi) < buffer.width)
            {
                buffer.data[(sprite.height - 1 + y - yi) * buffer.width + (x + xi)] = color;
            }
        }
    }
}

constexpr uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b)
{
    return (r << 16) | (g << 8) | b;
}

// error with rgb value conversion with bytes
// constexpr uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b)
// {
//     return (r << 24) | (g << 16) | (b << 8) | 255;
// }

int main()
{
    // debugging for rgb issue
    // uint32_t color = rgb_to_uint32(0, 255, 0); // Green
    // std::cout << "Green color packed: " << std::hex << "0x" << color << std::endl;

    // color = rgb_to_uint32(0, 0, 255); // Blue
    // std::cout << "Blue color packed: " << std::hex << "0x" << color << std::endl;

    const size_t buffer_width = 800;
    const size_t buffer_height = 600;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(buffer_width, buffer_height, "Space Invaders", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW\n";
        glfwTerminate();
        return -1;
    }

    gl_debug(__FILE__, __LINE__);

    std::cout << "Using OpenGL: " << glGetString(GL_VERSION) << "\n"
              << "Renderer: " << glGetString(GL_RENDERER) << "\n"
              << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

    glClearColor(0.13f, 0.55f, 0.13f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Buffer buffer{buffer_width, buffer_height, std::vector<uint32_t>(buffer_width * buffer_height)};
    buffer_clear(buffer, rgb_to_uint32(255, 0, 0));

    GLuint buffer_texture;
    glGenTextures(1, &buffer_texture);
    glBindTexture(GL_TEXTURE_2D, buffer_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, buffer.width, buffer.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer.data.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    GLuint fullscreen_triangle_vao;
    glGenVertexArrays(1, &fullscreen_triangle_vao);

    static const char *vertex_shader = R"(
        #version 410 core
        out vec2 TexCoord;
        void main() {
            TexCoord = vec2((gl_VertexID == 2) ? 2.0 : 0.0, (gl_VertexID == 1) ? 2.0 : 0.0);
            gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);
        })";

    static const char *fragment_shader = R"(
        #version 410 core
        uniform sampler2D buffer;
        in vec2 TexCoord;
        out vec4 outColor;
        void main() {
            outColor = texture(buffer, TexCoord);
        })";

    GLuint shader_program = glCreateProgram();
    auto create_and_attach_shader = [](GLuint program, GLenum type, const char *source)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, nullptr);
        glCompileShader(shader);
        validate_shader(shader);
        glAttachShader(program, shader);
        glDeleteShader(shader);
    };

    create_and_attach_shader(shader_program, GL_VERTEX_SHADER, vertex_shader);
    create_and_attach_shader(shader_program, GL_FRAGMENT_SHADER, fragment_shader);

    glLinkProgram(shader_program);
    if (!validate_program(shader_program))
    {
        glfwTerminate();
        return -1;
    }

    glUseProgram(shader_program);
    glUniform1i(glGetUniformLocation(shader_program, "buffer"), 0);
    glBindVertexArray(fullscreen_triangle_vao);

    Sprite alien_sprite{11, 8, {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0}};

    while (!glfwWindowShouldClose(window))
    {
        buffer_clear(buffer, rgb_to_uint32(0, 127, 0));
        buffer_draw_sprite(buffer, alien_sprite, 112, 128, rgb_to_uint32(255, 192, 203));

        glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, buffer.width, buffer.height, GL_RGBA, GL_UNSIGNED_BYTE, buffer.data.data());
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteTextures(1, &buffer_texture);
    glDeleteProgram(shader_program);
    glDeleteVertexArrays(1, &fullscreen_triangle_vao);

    glfwTerminate();
    return 0;
}
