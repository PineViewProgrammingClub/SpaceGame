#ifndef IMAGE_H
#define IMAGE_H

#include <GL/glew.h>

class Image {
private:
	GLuint VAO, VBO;	// vertex array, vertex buffer objects
	int drawSize;
public:
	Image(int width, int height, int size);
	~Image();
	void draw();
};

#endif	// IMAGE_H