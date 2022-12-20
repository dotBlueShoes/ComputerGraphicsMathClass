#include "Line.hpp"
#define _USE_MATH_DEFINES
#include <math.h>

bool Line::lineIntersectionCheck(const Line& other)
{
	if (fabs(this->directional.cross(other.directional).length()) == 0.f)
	{
		// proste rownolegle
		return false;
	}

	return true;
}

Vector Line::getLineIntersectionPoint(const Line& other)
{
	float t1 = (other.point - this->point).cross(other.directional).dot(this->directional.cross(other.directional)) / 
		(this->directional.cross(other.directional).length() * this->directional.cross(other.directional).length());

	//printf("Result: %f", t1);
	float x = this->directional.x * t1 + this->point.x;
	float y = this->directional.y * t1 + this->point.y;
	float z = this->directional.z * t1 + this->point.z;

	return Vector(x, y, z);
}

float Line::getAngleBetweenLines(const Line& other)
{
	return this->directional.angle(other.directional);
}

Vector Line::getLineAndPlaneIntersectionPoint(const Line& other)
{
	float t = (other.directional * -1).dot(this->point - other.point) / (other.directional.dot(this->directional));

	float x = this->directional.x * t + this->point.x;
	float y = this->directional.y * t + this->point.y;
	float z = this->directional.z * t + this->point.z;

	return Vector(x, y, z);
}

float Line::getAngleBetweenLineAndPlane(const Line& other)
{
	return M_PI / 2 - this->directional.angle(other.directional);
}

Line Line::getPlaneIntersection(const Line& plane)
{
	//float temp = (plane.directional * (this->point - plane.point)) / ( plane.directional * this->directional);

	Vector newDirectional = this->directional.cross(plane.directional);
	const float det = newDirectional.length();
	if (det != 0.0) {
		Vector newPoint = (
			(newDirectional.cross(plane.directional) * -8) +
			(this->directional.cross(newDirectional) * 14)
		) / det;
		return Line({ newDirectional }, newPoint);
	}
	
	return Line(0, 0, 0, 0, 0, 0);
}

Vector Line::getDirectional()
{
	return directional;
}

Vector Line::getPoint()
{
	return point;
}
