// Vec2.h
// By Frank Luna
// August 24, 2004.

#ifndef VEC2_H
#define VEC2_H

#include <windows.h>

class Vec2
{
public:
	Vec2();
	Vec2(double s, double t);
	Vec2(double d[2]);
	Vec2(const POINT& p);

	Vec2 operator+(const Vec2& rhs)const;
	Vec2 operator-(const Vec2& rhs)const;
	Vec2 operator-();

	operator POINT();

	void operator+=(const Vec2& rhs);
	void operator-=(const Vec2& rhs);
	void operator*=(double s);
	void operator/=(double s);

	double length();
	Vec2& normalize();

	double dot(const Vec2& rhs);

	Vec2& reflect(const Vec2& normal);

	// Data members.
	double x;
	double y;
};

// Define with left hand and right hand sides reversed
// so we can write both v*s and s*v.
Vec2 operator*(const Vec2& v, double s);
Vec2 operator*(double s, const Vec2& v);
Vec2 operator/(const Vec2& v, double s);
Vec2 operator/(double s, const Vec2& v);

#endif // VEC2_H