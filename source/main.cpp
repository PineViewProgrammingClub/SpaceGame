/******************************************************************************
*   main.cpp
*
*	Quite simply, it handles just about everything. 
*
*	Important Revision History:
*	23/10/14 - Added this comment.
*
******************************************************************************/

#include <SDL.h>
#include <GL\glew.h>
#include <GL\GL.h>
#include <iostream>
#include "Resource.h"
#include "Vector.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define START_POS_X 30
#define START_POS_Y 30
#define GAME_TITLE "Space Game"
#define VERSION_STRING "v0.0"
#define main main

int main(int argc, char** args){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL_Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_Window* window = SDL_CreateWindow(GAME_TITLE, START_POS_X, START_POS_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL);

	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);

	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		// Glew error
		std::cout << "GLEW Error" << std::endl;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	GLuint VAO,VBO,IBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	float verts[12] = { -1, 1, 0, 1, -1, -1, 0, 1, 1, -1, 0, 1 };
	int vertOffset = 0;
	glBufferData(GL_ARRAY_BUFFER, 12, &verts[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4, (GLvoid*) vertOffset);
	glEnableVertexAttribArray(0);

	unsigned int indices[3] = {0, 1, 2};
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3, &indices[0], GL_STATIC_DRAW);
	Shader* shader = loadShader("default");
	shader->bind();
	
	SDL_Event event;
	bool shouldExit = false;
	while (!shouldExit){
		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_a:
					std::cout << "a was pressed" << std::endl;
					break;
				}
				break;
			case SDL_QUIT:
				shouldExit = true;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event){
				case SDL_WINDOWEVENT_CLOSE:
					shouldExit = true;
					break;
				}
				break;
			}
		}
		// Update
		// draw
		SDL_GL_MakeCurrent(window, context);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		SDL_GL_SwapWindow(window);
	}


	//draw
	//SDL_GL_MakeCurrent(window, context);
	//SDL_GL_SwapWindow(window);
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);

	int retval;
	std::cin >> retval;
}