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

#define main main

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int START_POS_X = 30;
const int START_POS_Y = 30;
const char* GAME_TITLE = "Space Game";
const char* VERSION_STRING = "v0.0";

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
		//other stuff
	}


	//draw
	//SDL_GL_MakeCurrent(window, context);
	//SDL_GL_SwapWindow(window);
	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);

	int retval;
	std::cin >> retval;
}