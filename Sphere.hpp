#pragma once
#include "Vector.hpp"
#include "Line.hpp"
#include <array>

class Sphere {

public:
	Vector position;
	float radius;

	// CONSTRUCTORS
	Sphere(const Vector& newPosition, const float& newRadius) : position(newPosition), radius(newRadius) {};

    using IntersectionResult = std::array<Vector, 2>;
        

    IntersectionResult getIntersection(
        Line& line
    ) {
        Vector temp = line.getPoint() - this->position;
        float a = line.getDirectional().dot(line.getDirectional());
        float b = 2.0f * temp.dot(line.getDirectional());
        float c = temp.dot(temp) - this->radius * this->radius;
        float delta = b*b + (- 4 * a * c);
        if (delta < 0.0f) return {{{0, 0, 0}, {0, 0, 0}}}; // No intersection !
        float x1 = (-b - sqrt(delta)) / (2.0f * a);
        float x2 = (-b + sqrt(delta)) / (2.0f * a);

        return { { { line.getPoint() + line.getDirectional() * x1 }, { line.getPoint() + line.getDirectional() * x2 }} };
    }

};