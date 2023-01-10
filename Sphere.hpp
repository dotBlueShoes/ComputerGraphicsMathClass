#pragma once
#include "Vector.hpp"
#include "Line.hpp"
#include <array>

#include <iostream>

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

        {
            Vector prob = line.getPoint();
            Vector huh = line.getDirectional();
            std::cout << prob.x << ", " << prob.y << ", " << prob.z << '\n';
            std::cout << this->position.x << ", " << this->position.y << ", " << this->position.z << '\n';
            std::cout << huh.x << ", " << huh.y << ", " << huh.z << '\n';
        }

        Vector temp = line.getPoint() - this->position;
        float a = line.getDirectional().dot(line.getDirectional());
        float b = 2.0f * temp.dot(line.getDirectional());
        float c = temp.dot(temp) - this->radius * this->radius;

        { // Delta Equation
            float delta = b * b - (4 * a * c);
            if (delta < 0.0f)
                return IntersectionResult { // No intersection !
                    Vector {0, 0, 0}, 
                    Vector {0, 0, 0} 
                }; 
            else {
                float x1 = (-b - std::sqrt(delta)) / (2.0f * a);
                float x2 = (-b + std::sqrt(delta)) / (2.0f * a);

                {
                    std::cout << "2.\n" << x1 << ", " << x2 << '\n';
                    Vector aaa = line.getDirectional() * x1;
                    std::cout << "Result1 : " << aaa.x << ", " << aaa.y << ", " << aaa.z << '\n';
                    aaa = line.getDirectional() * x2;
                    std::cout << "Result2 : " << aaa.x << ", " << aaa.y << ", " << aaa.z << '\n';
                    std::cout << line.getPoint().x << ", " << line.getPoint().y << ", " << line.getPoint().z << '\n';
                }

                return IntersectionResult { 
                    Vector { line.getPoint() + (line.getDirectional() * x1) }, 
                    Vector { line.getPoint() + (line.getDirectional() * x2) } 
                };
            }
        }
        
    }

};