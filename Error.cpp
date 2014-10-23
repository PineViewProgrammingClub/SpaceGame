#include "Error.h"
#include <GL/glew.h>
#include <iostream>

void handleError(Error e, bool gle){
	if (gle){
		GLenum ErrorCheckValue = glGetError();
		while (ErrorCheckValue != GL_NO_ERROR) {
			std::cout << "GL Error " << e << ": " << gluErrorString(ErrorCheckValue) << std::endl;
			ErrorCheckValue = glGetError();
		}
	} else {
		std::cout << "Error " << e << std::endl;
	}
}