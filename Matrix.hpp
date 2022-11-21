#pragma once
#include "Vector.hpp"

class Matrix4x4
{
public:
	// Matrix
	float matrix[16];

	// Constructors
	Matrix4x4();
	Matrix4x4(float e0, float e1, float e2, float e3,
			float e4, float e5, float e6, float e7,
			float e8, float e9, float e10, float e11,
			float e12, float e13, float e14, float e15);
	Matrix4x4(const float* f);
	Matrix4x4(const Matrix4x4& mat);
	~Matrix4x4();

	Matrix4x4 add(const Matrix4x4& mat);
	Matrix4x4 operator+(const Matrix4x4& mat);
	Matrix4x4 subtract(const Matrix4x4& mat);
	Matrix4x4 operator-(const Matrix4x4& mat);
	Matrix4x4 multiply(const Matrix4x4 &mat);
	Matrix4x4 dot(const float f);
	Matrix4x4 operator*(const float f);

	void loadIdentity();
	bool invertMatrix(const Matrix4x4& m);
	Matrix4x4 getInverse();
	void invertThis();

	void transposeMatrix(const Matrix4x4& m);
	Matrix4x4 transposeThis();

	void translate(const Vector& trans);
	void scale(const Vector& s);
	void uniformScale(const float scaleFactor);
	void setRotationAxis(const double angle, const Vector& axis);
	void rotateX(const double angle);
	void rotateY(const double angle);
	void rotateZ(const double angle);
};

class Matrix3x3
{
public:
	// Matrix
	float matrix[9] = { 0.0 };

	// Constructors
	Matrix3x3();
	Matrix3x3(float e0, float e3, float e6, float e1, float e4, float e7, float e2, float e5, float e8);

	// Copy constructor
	Matrix3x3& operator=(const Matrix3x3& value);

	~Matrix3x3();
};