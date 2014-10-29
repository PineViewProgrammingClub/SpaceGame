#include "Image.h"
#include "Error.h"

Image::Image(int width, int height, int size) {
	drawSize = size;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	handleError(Error::GL_CREATE_VBO, true);
}

Image::~Image(){
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBO);

	glBindVertexArray(0);
	glDeleteVertexArrays(1, &VAO);

	handleError(Error::GL_DESTROY_VBO, true);
}

void Image::draw(){
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glDrawElements(GL_TRIANGLES, drawSize, GL_UNSIGNED_INT, 0);
}