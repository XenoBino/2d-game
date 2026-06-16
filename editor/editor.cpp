#include <vector>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include "glad/glad.h"
#include "2d-eng/die.hpp"

GLuint get_program(const std::string_view& name) {
	if (name != "main") return 0;
	GLuint program = glCreateProgram();
	GLuint vert = glCreateShader(GL_VERTEX_SHADER);
	GLuint frag = glCreateShader(GL_FRAGMENT_SHADER);
	const char *vert_src =
		"#version 460 core\n"
		"layout (location = 0) in vec3 i_Pos;"
		"void main() { gl_Position = vec4(i_Pos, 1.0); }"
	;
	const char *frag_src =
		"#version 460 core\n"
		"layout (location = 0) out vec4 o_Color;"
		"void main() { o_Color = vec4(1.0, 0.0, 0.0, 1.0); }"
	;

	glShaderSource(vert, 1, &vert_src, nullptr);
	glShaderSource(frag, 1, &frag_src, nullptr);
	glCompileShader(vert);
	glCompileShader(frag);
	glAttachShader(program, vert);
	glAttachShader(program, frag);
	glLinkProgram(program);
	glDeleteShader(vert);
	glDeleteShader(frag);
	return program;
}

int main(int argc, char **argv) {
	uint32_t width = 720, height = 480;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("editor", width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_NO_ERROR, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG | SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GLContext ctx = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, ctx);
	if (!gladLoadGL(SDL_GL_GetProcAddress))
		die("Failed to load OpenGL");

	struct Vertex2D {
		struct { float x, y, z; } position;
	};

	GLuint program = get_program("main");
	GLuint vbo = 0, vao = 0, vertex_count = 0;
	{
	std::vector<Vertex2D> vertices = {
		{ { -0.5f,  0.5f, 0.1f } },
		{ { -0.5f, -0.5f, 0.1f } },
		{ {  0.5f, -0.5f, 0.1f } },
		{ {  0.5f, -0.5f, 0.1f } },
		{ {  0.5f,  0.5f, 0.1f } },
		{ { -0.5f,  0.5f, 0.1f } },
	};

	vertex_count = vertices.size();

	glCreateBuffers(1, &vbo);
	glNamedBufferStorage(vbo, vertices.size() * sizeof(vertices[0]), vertices.data(), 0);

	glCreateVertexArrays(1, &vao);
	glEnableVertexArrayAttrib(vao, 0);
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(Vertex2D));
	glVertexArrayAttribBinding(vao, 0, 0);
	glVertexArrayAttribFormat(vao, 0, 3, GL_FLOAT, GL_FALSE, offsetof(Vertex2D, position));
	}

	glClearColor(1.0f, 0.0f, 1.0f, 0.0f);
	bool should_close = false;
	while (true) {
		SDL_Event e = {};
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_WINDOW_DESTROYED ||
				e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
				should_close = true;

			if (e.type == SDL_EVENT_WINDOW_RESIZED) {
				int width_ = 0, height_ = 0;
				SDL_GetWindowSizeInPixels(window, &width_, &height_);
				glViewport(0, 0, width_, height_);
				width = width_;
				height = height_;
			}
		}

		if (should_close) break;

		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, vertex_count);

		SDL_GL_SwapWindow(window);
	}
	return 0;
}
