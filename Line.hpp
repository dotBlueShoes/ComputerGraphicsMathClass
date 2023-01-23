#pragma once
#include "Vector.hpp"

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

	bool lineIntersectionCheck(const Line& other);
	Vector getLineIntersectionPoint(const Line& other);
	float getAngleBetweenLines(const Line& other);

	Vector getLineAndPlaneIntersectionPoint(const Line& other);
	float getAngleBetweenLineAndPlane(const Line& other);

	Line getPlaneIntersection(const Line& other);

	static bool isRayCastIntersecting(Line& line);

	Vector getDirectional();
	Vector getPoint();
};