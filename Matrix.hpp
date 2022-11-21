#pragma once

class Matrix3n
{
public:
	// Matrix
	float matrix[9] = { 0.0 };

	// Constructors
	Matrix3n();
	Matrix3n(float e0, float e3, float e6, float e1, float e4, float e7, float e2, float e5, float e8);

	// Copy constructor
	Matrix3n& operator=(const Matrix3n& value);

	~Matrix3n();
};

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
};