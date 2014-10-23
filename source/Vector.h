/******************************************************************************
*   Vector.h - Tristan Lee
*
*	Holds an 'X' and 'Y' coordinate in the form of a double, which can be 
*	changed later, if needed.
*
******************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
	double x,y;
public:
	Vector::Vector(double nx, double ny);		// 'nx' is for New X-Pos and 'ny' is for New Y-Pos
	double getX();
	double getY();
	void setX(double nx);		// 'nx' is for New X-Pos
	void setY(double ny);		// 'ny' is for New Y-Pos
	void print();				// There may be a use for this sometime -- It's just for testing purposes
};

#endif