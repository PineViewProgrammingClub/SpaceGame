/******************************************************************************
*	Vector.cpp - Tristan Lee
*
*	Holds an 'X' and 'Y' coordinate in the form of a double, which can be 
*	changed later, if needed.
*
******************************************************************************/

#include "Vector.h"
#include <iostream>

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
