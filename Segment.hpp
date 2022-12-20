#pragma once
#include "Vector.hpp"
#include "Line.hpp"

class Segment {
	Line getLineBetween(const Vector& beginingPoint, const Vector& endPoint) { return { endPoint - beginingPoint, beginingPoint }; }

public:
	Vector pointA, pointB;
	Line lineBetween;

	// CONSTRUCTORS
	Segment(const Vector& beginingPoint, const Vector& endPoint) : 
		pointA(beginingPoint), pointB(endPoint), 
		lineBetween(getLineBetween(beginingPoint, endPoint)) 
	{};

};
