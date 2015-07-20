#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include "Shader.h"

int main(int argc, char * argv[])
{
	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_Window* window = SDL_CreateWindow("OpenGL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);

	glewInit();

	float vertices[] = {
		0.0f,  0.5f,
		0.5f, -0.5f,
	   -0.5f, -0.5f
	};

	std::cout << &glGenVertexArrays << std::endl;

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	Shader shader("Shader.shader");

	GLint posAttrib = glGetAttribLocation(shader.shaderID, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);

	SDL_Event windowEvent;
	while (true)
	{
		if (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) break;
		}

		SDL_GL_SwapWindow(window);
	}

	glDrawArrays(GL_TRIANGLES, 0, 3);

	SDL_GL_DeleteContext(context);
	SDL_Quit();

	return 0;
}