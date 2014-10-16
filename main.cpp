#include <SDL.h>
#include <GL\glew.h>
#include <GL\GL.h>
#include <iostream>

#define main main

int main(int argc, char** args){
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialization failed. SDL_Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("Space Game", 30, 30, 800, 600, SDL_WINDOW_OPENGL);

	SDL_Event event;
	while (true){
		while (SDL_PollEvent(&event)){
			switch (event.type){
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_a:
					std::cout << "a was pressed" << std::endl;
					break;
				}

			}
		}
		//other stuff
	}

	int retval;
	std::cin >> retval;
}