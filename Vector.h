#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <iostream>

class Vector
{
public:
	float x, y, z;

	//Constructors
	Vector();

	Vector(float x, float y, float z);

	Vector(Vector p1, Vector p2);

	//Deconstrtuctor
	~Vector();

	//Addition
	void add(Vector v);

	//Subtraction
	void sub(Vector v);

	//Scalar division
	void div(float f);

	//Scalar multiplication
	void mul(float f);

	//Vector length
	float length();

	//Vector normalization
	void normalize();

	//Dot product
	Vector dot(Vector v);

	float dotProduct(Vector v);

	//Cross product
	Vector cross(Vector v);

	//Angle between two vectors
	float angle(Vector v);
};

#endif // VECTOR_H