#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture {
private:
	GLuint id;
	int width, height;
public:
	Texture(unsigned char* data, int w, int h);
	~Texture();
	void bind();
};

#endif