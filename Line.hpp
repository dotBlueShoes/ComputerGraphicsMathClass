#pragma once
#include "Vector.hpp"
#include "Point.hpp"

class Line{
	Vector directional; // Direction of this straight line.
	Vector point;        // Any point of this straight line.

public:
	// CONSTRUCTORS
	Line(const Vector& newDirectional, const Vector& newPoint
	) : directional(newDirectional), point(newPoint) {}

	Line(
		const Vector& newDirectional, const float& newX, const float& newY, const float& newZ
	) : directional(newDirectional), point(newX, newY, newZ) {}

	Line(
		const float& newDirectionalX, const float& newDirectionalY, const float& newDirectionalZ, 
		const float& newX, const float& newY, const float& newZ
	) : directional(newDirectionalX, newDirectionalY, newDirectionalZ), point(newX, newY, newZ) {}

	bool lineIntersectionCheck(Line& other);
	Vector getLineIntersectionPoint(Line& other);
	float getAngleBetweenLines(Line& other);

	Vector getLineAndPlaneIntersectionPoint(Line& other);
	float getAngleBetweenLineAndPlane(Line& other);

	Line getPlaneIntersection(Line& other);

	Vector getDirectional();
	Vector getPoint();
};