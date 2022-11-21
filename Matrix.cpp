#include "Matrix.hpp"

Matrix4x4::Matrix4x4()
{
}

Matrix4x4::Matrix4x4(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7, float e8, float e9, float e10, float e11, float e12, float e13, float e14, float e15)
{
	matrix[0] = e0;
	matrix[1] = e1;
	matrix[2] = e2;
	matrix[3] = e3;
	matrix[4] = e4;
	matrix[5] = e5;
	matrix[6] = e6;
	matrix[7] = e7;
	matrix[8] = e8;
	matrix[9] = e9;
	matrix[10] = e10;
	matrix[11] = e11;
	matrix[12] = e12;
	matrix[13] = e13;
	matrix[14] = e14;
	matrix[15] = e15;
}

Matrix4x4::Matrix4x4(const float* f)
{
	memcpy(matrix, f, 16 * sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4& mat)
{
	memcpy(matrix, mat.matrix, 16 * sizeof(float));
}

Matrix4x4::~Matrix4x4()
{
}

Matrix4x4 Matrix4x4::add(const Matrix4x4& mat)
{
	return Matrix4x4(matrix[0] + mat.matrix[0],
				matrix[1] + mat.matrix[1],
				matrix[2] + mat.matrix[2],
				matrix[3] + mat.matrix[3],
				matrix[4] + mat.matrix[4],
				matrix[5] + mat.matrix[5],
				matrix[6] + mat.matrix[6],
				matrix[7] + mat.matrix[7],
				matrix[8] + mat.matrix[8],
				matrix[9] + mat.matrix[9],
				matrix[10] + mat.matrix[10],
				matrix[11] + mat.matrix[11],
				matrix[12] + mat.matrix[12],
				matrix[13] + mat.matrix[13],
				matrix[14] + mat.matrix[14],
				matrix[15] + mat.matrix[15]);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat)
{
	return add(mat);
}

Matrix4x4 Matrix4x4::subtract(const Matrix4x4& mat)
{
	return Matrix4x4(matrix[0] - mat.matrix[0],
					matrix[1] - mat.matrix[1],
					matrix[2] - mat.matrix[2],
					matrix[3] - mat.matrix[3],
					matrix[4] - mat.matrix[4],
					matrix[5] - mat.matrix[5],
					matrix[6] - mat.matrix[6],
					matrix[7] - mat.matrix[7],
					matrix[8] - mat.matrix[8],
					matrix[9] - mat.matrix[9],
					matrix[10] - mat.matrix[10],
					matrix[11] - mat.matrix[11],
					matrix[12] - mat.matrix[12],
					matrix[13] - mat.matrix[13],
					matrix[14] - mat.matrix[14],
					matrix[15] - mat.matrix[15]);
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& mat)
{
	return subtract(mat);
}

Matrix4x4 Matrix4x4::multiply(const Matrix4x4& mat)
{
	if (matrix[3] == 0.0f && matrix[7] == 0.0f && matrix[11] == 0.0f && matrix[15] == 1.0f &&
		mat.matrix[3] == 0.0f && mat.matrix[7] == 0.0f && mat.matrix[11] == 0.0f && mat.matrix[15] == 1.0f)
	{
		return Matrix4x4(matrix[0] * mat.matrix[0] + matrix[4] * mat.matrix[1] + matrix[8] * mat.matrix[2],
						matrix[1] * mat.matrix[0] + matrix[5] * mat.matrix[1] + matrix[9] * mat.matrix[2], 
						matrix[2] * mat.matrix[0] + matrix[6] * mat.matrix[1] + matrix[10] * mat.matrix[2], 
						0.0f,
						matrix[0] * mat.matrix[4] + matrix[4] * mat.matrix[5] + matrix[8] * mat.matrix[6], 
						matrix[1] * mat.matrix[4] + matrix[5] * mat.matrix[5] + matrix[9] * mat.matrix[6], 
						matrix[2] * mat.matrix[4] + matrix[6] * mat.matrix[5] + matrix[10] * mat.matrix[6], 
						0.0f,
						matrix[0] * mat.matrix[8] + matrix[4] * mat.matrix[9] + matrix[8] * mat.matrix[10], 
						matrix[1] * mat.matrix[8] + matrix[5] * mat.matrix[9] + matrix[9] * mat.matrix[10], 
						matrix[2] * mat.matrix[8] + matrix[6] * mat.matrix[9] + matrix[10] * mat.matrix[10], 
						0.0f,
						matrix[0] * mat.matrix[12] + matrix[4] * mat.matrix[13] + matrix[8] * mat.matrix[14] + matrix[12], 
						matrix[1] * mat.matrix[12] + matrix[5] * mat.matrix[13] + matrix[9] * mat.matrix[14] + matrix[13],
						matrix[2] * mat.matrix[12] + matrix[6] * mat.matrix[13] + matrix[10] * mat.matrix[14] + matrix[14],
						1.0f);
	}
}

Matrix4x4 Matrix4x4::dot(const float f)
{
	return Matrix4x4(matrix[0] * f,
					matrix[1] * f,
					matrix[2] * f, 
					matrix[3] * f, 
					matrix[4] * f, 
					matrix[5] * f, 
					matrix[6] * f, 
					matrix[7] * f, 
					matrix[8] * f, 
					matrix[9] * f, 
					matrix[10] * f, 
					matrix[11] * f, 
					matrix[12] * f, 
					matrix[13] * f, 
					matrix[14] * f, 
					matrix[15] * f);
}

Matrix4x4 Matrix4x4::operator*(const float f)
{
	return dot(f);
}

void Matrix4x4::loadIdentity()
{
	memset(matrix, 0, 16 * sizeof(float));
	matrix[0] = 1.0f;
	matrix[5] = 1.0f;
	matrix[10] = 1.0f;
	matrix[15] = 1.0f;
}

bool Matrix4x4::invertMatrix(const Matrix4x4& m)
{
	float det;

	matrix[0] = m.matrix[5] * m.matrix[10] * m.matrix[15] -
		m.matrix[5] * m.matrix[11] * m.matrix[14] -
		m.matrix[9] * m.matrix[6] * m.matrix[15] +
		m.matrix[9] * m.matrix[7] * m.matrix[14] +
		m.matrix[13] * m.matrix[6] * m.matrix[11] -
		m.matrix[13] * m.matrix[7] * m.matrix[10];

	matrix[4] = -m.matrix[4] * m.matrix[10] * m.matrix[15] +
		m.matrix[4] * m.matrix[11] * m.matrix[14] +
		m.matrix[8] * m.matrix[6] * m.matrix[15] -
		m.matrix[8] * m.matrix[7] * m.matrix[14] -
		m.matrix[12] * m.matrix[6] * m.matrix[11] +
		m.matrix[12] * m.matrix[7] * m.matrix[10];

	matrix[8] = m.matrix[4] * m.matrix[9] * m.matrix[15] -
		m.matrix[4] * m.matrix[11] * m.matrix[13] -
		m.matrix[8] * m.matrix[5] * m.matrix[15] +
		m.matrix[8] * m.matrix[7] * m.matrix[13] +
		m.matrix[12] * m.matrix[5] * m.matrix[11] -
		m.matrix[12] * m.matrix[7] * m.matrix[9];

	matrix[12] = -m.matrix[4] * m.matrix[9] * m.matrix[14] +
		m.matrix[4] * m.matrix[10] * m.matrix[13] +
		m.matrix[8] * m.matrix[5] * m.matrix[14] -
		m.matrix[8] * m.matrix[6] * m.matrix[13] -
		m.matrix[12] * m.matrix[5] * m.matrix[10] +
		m.matrix[12] * m.matrix[6] * m.matrix[9];

	matrix[1] = -m.matrix[1] * m.matrix[10] * m.matrix[15] +
		m.matrix[1] * m.matrix[11] * m.matrix[14] +
		m.matrix[9] * m.matrix[2] * m.matrix[15] -
		m.matrix[9] * m.matrix[3] * m.matrix[14] -
		m.matrix[13] * m.matrix[2] * m.matrix[11] +
		m.matrix[13] * m.matrix[3] * m.matrix[10];

	matrix[5] = m.matrix[0] * m.matrix[10] * m.matrix[15] -
		m.matrix[0] * m.matrix[11] * m.matrix[14] -
		m.matrix[8] * m.matrix[2] * m.matrix[15] +
		m.matrix[8] * m.matrix[3] * m.matrix[14] +
		m.matrix[12] * m.matrix[2] * m.matrix[11] -
		m.matrix[12] * m.matrix[3] * m.matrix[10];

	matrix[9] = -m.matrix[0] * m.matrix[9] * m.matrix[15] +
		m.matrix[0] * m.matrix[11] * m.matrix[13] +
		m.matrix[8] * m.matrix[1] * m.matrix[15] -
		m.matrix[8] * m.matrix[3] * m.matrix[13] -
		m.matrix[12] * m.matrix[1] * m.matrix[11] +
		m.matrix[12] * m.matrix[3] * m.matrix[9];

	matrix[13] = m.matrix[0] * m.matrix[9] * m.matrix[14] -
		m.matrix[0] * m.matrix[10] * m.matrix[13] -
		m.matrix[8] * m.matrix[1] * m.matrix[14] +
		m.matrix[8] * m.matrix[2] * m.matrix[13] +
		m.matrix[12] * m.matrix[1] * m.matrix[10] -
		m.matrix[12] * m.matrix[2] * m.matrix[9];

	matrix[2] = m.matrix[1] * m.matrix[6] * m.matrix[15] -
		m.matrix[1] * m.matrix[7] * m.matrix[14] -
		m.matrix[5] * m.matrix[2] * m.matrix[15] +
		m.matrix[5] * m.matrix[3] * m.matrix[14] +
		m.matrix[13] * m.matrix[2] * m.matrix[7] -
		m.matrix[13] * m.matrix[3] * m.matrix[6];

	matrix[6] = -m.matrix[0] * m.matrix[6] * m.matrix[15] +
		m.matrix[0] * m.matrix[7] * m.matrix[14] +
		m.matrix[4] * m.matrix[2] * m.matrix[15] -
		m.matrix[4] * m.matrix[3] * m.matrix[14] -
		m.matrix[12] * m.matrix[2] * m.matrix[7] +
		m.matrix[12] * m.matrix[3] * m.matrix[6];

	matrix[10] = m.matrix[0] * m.matrix[5] * m.matrix[15] -
		m.matrix[0] * m.matrix[7] * m.matrix[13] -
		m.matrix[4] * m.matrix[1] * m.matrix[15] +
		m.matrix[4] * m.matrix[3] * m.matrix[13] +
		m.matrix[12] * m.matrix[1] * m.matrix[7] -
		m.matrix[12] * m.matrix[3] * m.matrix[5];

	matrix[14] = -m.matrix[0] * m.matrix[5] * m.matrix[14] +
		m.matrix[0] * m.matrix[6] * m.matrix[13] +
		m.matrix[4] * m.matrix[1] * m.matrix[14] -
		m.matrix[4] * m.matrix[2] * m.matrix[13] -
		m.matrix[12] * m.matrix[1] * m.matrix[6] +
		m.matrix[12] * m.matrix[2] * m.matrix[5];

	matrix[3] = -m.matrix[1] * m.matrix[6] * m.matrix[11] +
		m.matrix[1] * m.matrix[7] * m.matrix[10] +
		m.matrix[5] * m.matrix[2] * m.matrix[11] -
		m.matrix[5] * m.matrix[3] * m.matrix[10] -
		m.matrix[9] * m.matrix[2] * m.matrix[7] +
		m.matrix[9] * m.matrix[3] * m.matrix[6];

	matrix[7] = m.matrix[0] * m.matrix[6] * m.matrix[11] -
		m.matrix[0] * m.matrix[7] * m.matrix[10] -
		m.matrix[4] * m.matrix[2] * m.matrix[11] +
		m.matrix[4] * m.matrix[3] * m.matrix[10] +
		m.matrix[8] * m.matrix[2] * m.matrix[7] -
		m.matrix[8] * m.matrix[3] * m.matrix[6];

	matrix[11] = -m.matrix[0] * m.matrix[5] * m.matrix[11] +
		m.matrix[0] * m.matrix[7] * m.matrix[9] +
		m.matrix[4] * m.matrix[1] * m.matrix[11] -
		m.matrix[4] * m.matrix[3] * m.matrix[9] -
		m.matrix[8] * m.matrix[1] * m.matrix[7] +
		m.matrix[8] * m.matrix[3] * m.matrix[5];

	matrix[15] = m.matrix[0] * m.matrix[5] * m.matrix[10] -
		m.matrix[0] * m.matrix[6] * m.matrix[9] -
		m.matrix[4] * m.matrix[1] * m.matrix[10] +
		m.matrix[4] * m.matrix[2] * m.matrix[9] +
		m.matrix[8] * m.matrix[1] * m.matrix[6] -
		m.matrix[8] * m.matrix[2] * m.matrix[5];

	det = m.matrix[0] * matrix[0] + m.matrix[1] * matrix[4] + m.matrix[2] * matrix[8] + m.matrix[3] * matrix[12];

	if (det == 0)
		return false;

	det = 1.0 / det;
	
	for (int i = 0; i < 16; i++)
		matrix[i] = matrix[i] * det;

	return true;
}

Matrix4x4 Matrix4x4::getInverse()
{
	Matrix4x4 res;
	res.inverseMatrix(*this);
	return res;
}

void Matrix4x4::invertThis()
{
	invertMatrix(*this);
}

void Matrix4x4::transposeMatrix(const Matrix4x4& m)
{
	matrix[0] = m.matrix[0];
	matrix[4] = m.matrix[1];
	matrix[8] = m.matrix[2];
	matrix[12] = m.matrix[3];
	matrix[1] = m.matrix[4];
	matrix[5] = m.matrix[5];
	matrix[9] = m.matrix[6];
	matrix[13] = m.matrix[7];
	matrix[2] = m.matrix[8];
	matrix[6] = m.matrix[9];
	matrix[10] = m.matrix[10];
	matrix[14] = m.matrix[11];
	matrix[3] = m.matrix[12];
	matrix[7] = m.matrix[13];
	matrix[11] = m.matrix[14];
	matrix[15] = m.matrix[15];
}

Matrix4x4 Matrix4x4::transposeThis()
{
	Matrix4x4 res;
	res.transposeMatrix(*this);
	return res;
}

void Matrix4x4::translate(const Vector& trans)
{
	matrix[12] = trans.x;
	matrix[13] = trans.y;
	matrix[14] = trans.z;
}

void Matrix4x4::scale(const Vector& s)
{
	loadIdentity();
	matrix[0] = s.x;
	matrix[5] = s.y;
	matrix[10] = s.z;
}

void Matrix4x4::uniformScale(const float scaleFactor)
{
	loadIdentity();
	matrix[0] = matrix[5] = matrix[10] = scaleFactor;
}

void Matrix4x4::setRotationAxis(const double angle, const Vector& axis)
{
	Vector u = axis.normalize();

	float sin = (float)sin(M_PI * angle / 180);
	float cos = (float)cos(M_PI * angle / 180);

	loadIdentity();

	matrix[0] = u.x * u.x + cos * (1.0f - u.x * u.x);
	matrix[4] = u.x * u.y * (1.0f - cos) - sin * u.z;
	matrix[8] = u.x * u.z * (1.0f - cos) + sin * u.y;

	matrix[1] = u.x * u.y * (1.0f - cos) + sin * u.z;
	matrix[5] = u.y * u.y + cos * (1.0f - u.y * u.y);
	matrix[9] = u.y * u.z * (1.0f - cos) - sin * u.x;

	matrix[2] = u.x * u.z * (1.0f - cos) - sin * u.y;
	matrix[6] = u.y * u.z * (1.0f - cos) + sin * u.x;
	matrix[10] = u.z * u.z + cos * (1.0f - u.z * u.z);
}

void Matrix4x4::rotateX(const double angle)
{
	loadIdentity();

	matrix[5] = (float)cos(M_PI * angle / 180);
	matrix[6] = (float)sin(M_PI * angle / 180);

	matrix[9] = -matrix[6];
	matrix[10] = matrix[5];
}

void Matrix4x4::rotateY(const double angle)
{
	loadIdentity();

	matrix[0] = (float)cos(M_PI * angle / 180);
	matrix[2] = -(float)sin(M_PI * angle / 180);

	matrix[8] = -matrix[2];
	matrix[10] = matrix[0];
}

void Matrix4x4::rotateZ(const double angle)
{
	loadIdentity();

	matrix[0] = (float)cos(M_PI * angle / 180);
	matrix[1] = (float)sin(M_PI * angle / 180);

	matrix[4] = -matrix[1];
	matrix[5] = matrix[0];
}

Matrix3x3::Matrix3x3()
{
}

Matrix3x3::Matrix3x3(float e0, float e3, float e6, float e1, float e4, float e7, float e2, float e5, float e8)
{
	matrix[0] = e0;
	matrix[1] = e1;
	matrix[2] = e2;
	matrix[3] = e3;
	matrix[4] = e4;
	matrix[5] = e5;
	matrix[6] = e6;
	matrix[7] = e7;
	matrix[8] = e8;
}

Matrix3x3::~Matrix3x3()
{
}
