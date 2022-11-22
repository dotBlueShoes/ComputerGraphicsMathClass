#pragma once
#include "Constants.hpp"
#include "Vector.hpp"

class Matrix4x4
{
public:

	// Matrix
	float matrix[16];

	// Constructors
	Matrix4x4();
	Matrix4x4(
		const float& e0,  const float& e1,  const float& e2,  const float& e3,
		const float& e4,  const float& e5,  const float& e6,  const float& e7,
		const float& e8,  const float& e9,  const float& e10, const float& e11,
		const float& e12, const float& e13, const float& e14, const float& e15
	);
	Matrix4x4(const float& f);
	Matrix4x4(const Matrix4x4& mat);
	~Matrix4x4();

	bool operator==(Matrix4x4 other);

	Matrix4x4 add(const Matrix4x4& mat);
	Matrix4x4 operator+(const Matrix4x4& mat);
	Matrix4x4 subtract(const Matrix4x4& mat);
	Matrix4x4 operator-(const Matrix4x4& mat);
	Matrix4x4 multiply(const Matrix4x4 &mat);
	Matrix4x4 dot(const float& f);
	Matrix4x4 operator*(const float& f);

	void loadIdentity();
	bool invertMatrix(const Matrix4x4& m);
	Matrix4x4 getInverse();
	void invertThis();

	void transposeMatrix(const Matrix4x4& m);
	Matrix4x4 transposeThis();

	void translate(const Vector& trans);
	void scale(const Vector& s);
	void uniformScale(const float& scaleFactor);
	void setRotationAxis(const double& angle, const Vector& axis);
	void rotateX(const double& angle);
	void rotateY(const double& angle);
	void rotateZ(const double& angle);

	std::string toString();
};

class Matrix3x3
{
public:
	// Matrix
	float matrix[9];

	// Constructors
	Matrix3x3();
	Matrix3x3(
		//const float& e0, const float& e3, const float& e6, 
		//const float& e1, const float& e4, const float& e7, 
		//const float& e2, const float& e5, const float& e8
		const float& e0, const float& e1, const float& e2,
		const float& e3, const float& e4, const float& e5,
		const float& e6, const float& e7, const float& e8
	);

	// Copy constructor
	Matrix3x3& operator=(const Matrix3x3& value);

	~Matrix3x3();
};