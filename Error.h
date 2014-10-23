/******************************************************************************
*   Error.h - Tristan Lee
*
*	Handles errors when they occur with a specific error code. It will be 
*	changed to a hex system, when Space Calerb gets the time.
*
******************************************************************************/

#ifndef ERROR_H
#define ERROR_H

enum Error : int {
	NO_ERROR = 0,
	UNCAUGHT = 1,
	UNKNOWN_FATAL = 2,
	UNKNOWN_NORMAL = 3,
	CREATE_WINDOW = 101,
	LOAD_FILE = 102,
	SDL_UNCAUGHT = 201,
	SDL_UNKNOWN_FATAL = 202,
	SDL_UNKNOWN_NORMAL = 203,
	GL_UNCAUGHT = 301,
	GL_UNKNOWN_FATAL = 302,
	GL_UNKNOWN_NORMAL = 303,
	GL_CREATE_SHADER = 304,
	GL_BIND_SHADER = 305,
	GL_DESTROY_SHADER = 306,
	GL_CREATE_VBO = 307,
	GL_BIND_VBO = 308,
	GL_DESTROY_VBO = 309,
	GL_CREATE_VAO = 310,
	GL_BIND_VAO = 311,
	GL_DESTROY_VAO = 312,
	GL_DRAW = 313,
	GL_GLEW_INIT = 314,
	TEST_BEFORE = 501,
	TEST_AFTER = 599
};
void handleError(Error, bool);

#endif