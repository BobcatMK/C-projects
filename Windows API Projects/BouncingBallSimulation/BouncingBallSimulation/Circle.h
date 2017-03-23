// Circle.h
// By Frank Luna
// August 24, 2004.

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Vec2.h"

class Circle
{
public:
	Circle();
	Circle(double R, const Vec2& center);

	bool hits(Circle& A, Vec2& normal);

	double r; // radius
	Vec2  c; // center point
};
#endif // CIRCLE_H