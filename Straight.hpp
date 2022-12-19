#pragma once
#include "Vector.hpp"
#include "Point.hpp"

class Straight{
	Vector directional; // Direction of this straight line.
	Point point;        // Any point of this straight line.

public:
	// CONSTRUCTORS
	Straight(const Vector& newDirectional, const Point newPoint
	) : directional(newDirectional), point(newPoint) {};
	Straight(
		const Vector& newDirectional, const float& newX, const float& newY, const float& newZ
	) : directional(newDirectional), point(newX, newY, newZ) {};
	Straight(
		const float& newDirectionalX, const float& newDirectionalY, const float& newDirectionalZ, 
		const float& newX, const float& newY, const float& newZ
	) : directional(newDirectionalX, newDirectionalY, newDirectionalZ), point(newX, newY, newZ) {};

};