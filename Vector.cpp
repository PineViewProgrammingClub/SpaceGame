// "Vector.cpp" - Tristan
// A simple vector that stores the x and y coordinates of stuff in stuff

#include <iostream>
#include "Vector.h"

Vector::Vector(double nx, double ny) {
	x = nx;
	y = ny;
}

double Vector::getX() {
	return x;
}

double Vector::getY() {
	return y;
}

void Vector::setX(double nx) {
	x = nx;
}

void Vector::setY(double ny) {
	y = ny;
}

void Vector::print() {
	std::cout << "Vector: (" << x << "," << y << ")" << std::endl;
}
