#include "Matrix.hpp"

Matrix4x4::Matrix4x4() : matrix {0} {}

Matrix4x4::Matrix4x4(
	const float& e0, const float& e1, const float& e2, const float& e3,
	const float& e4, const float& e5, const float& e6, const float& e7,
	const float& e8, const float& e9, const float& e10, const float& e11,
	const float& e12, const float& e13, const float& e14, const float& e15
) : matrix { e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15 } {}

Matrix4x4::Matrix4x4(const float& f)
{
	memcpy(matrix, &f, 16 * sizeof(float));
}

Matrix4x4::Matrix4x4(const Matrix4x4& mat)
{
	memcpy(matrix, mat.matrix, 16 * sizeof(float));
}

Matrix4x4::~Matrix4x4() {}

bool Matrix4x4::operator==(Matrix4x4 other) {
	if (matrix[0]  == other.matrix[0]  &&
		matrix[1]  == other.matrix[1]  &&
		matrix[2]  == other.matrix[2]  &&
		matrix[3]  == other.matrix[3]  &&
		matrix[4]  == other.matrix[4]  &&
		matrix[5]  == other.matrix[5]  &&
		matrix[6]  == other.matrix[6]  &&
		matrix[7]  == other.matrix[7]  &&
		matrix[8]  == other.matrix[8]  &&
		matrix[9]  == other.matrix[9]  &&
		matrix[10] == other.matrix[10] &&
		matrix[11] == other.matrix[11] &&
		matrix[12] == other.matrix[12] &&
		matrix[13] == other.matrix[13] &&
		matrix[14] == other.matrix[14] &&
		matrix[15] == other.matrix[15])
		return true;
	else
		return false;
}

Matrix4x4 Matrix4x4::add(const Matrix4x4& mat)
{
	return Matrix4x4(
		matrix[0] + mat.matrix[0],
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
		matrix[15] + mat.matrix[15]
	);
}

Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat)
{
	return add(mat);
}

Matrix4x4 Matrix4x4::subtract(const Matrix4x4& mat)
{
	return Matrix4x4(
		matrix[0] - mat.matrix[0],
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
		matrix[15] - mat.matrix[15]
	);
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& mat)
{
	return subtract(mat);
}

Matrix4x4 Matrix4x4::multiply(const Matrix4x4& other)
{
	//if (matrix[3] == 0.0f && 
	//	matrix[7] == 0.0f && 
	//	matrix[11] == 0.0f && 
	//	matrix[15] == 1.0f &&
	//	mat.matrix[3] == 0.0f && 
	//	mat.matrix[7] == 0.0f && 
	//	mat.matrix[11] == 0.0f && 
	//	mat.matrix[15] == 1.0f
	//) {
	//	return Matrix4x4(
	//		matrix[0] * mat.matrix[0] + matrix[4] * mat.matrix[1] + matrix[8] * mat.matrix[2],
	//		matrix[1] * mat.matrix[0] + matrix[5] * mat.matrix[1] + matrix[9] * mat.matrix[2], 
	//		matrix[2] * mat.matrix[0] + matrix[6] * mat.matrix[1] + matrix[10] * mat.matrix[2], 
	//		0.0f,
	//		matrix[0] * mat.matrix[4] + matrix[4] * mat.matrix[5] + matrix[8] * mat.matrix[6], 
	//		matrix[1] * mat.matrix[4] + matrix[5] * mat.matrix[5] + matrix[9] * mat.matrix[6], 
	//		matrix[2] * mat.matrix[4] + matrix[6] * mat.matrix[5] + matrix[10] * mat.matrix[6], 
	//		0.0f,
	//		matrix[0] * mat.matrix[8] + matrix[4] * mat.matrix[9] + matrix[8] * mat.matrix[10], 
	//		matrix[1] * mat.matrix[8] + matrix[5] * mat.matrix[9] + matrix[9] * mat.matrix[10], 
	//		matrix[2] * mat.matrix[8] + matrix[6] * mat.matrix[9] + matrix[10] * mat.matrix[10], 
	//		0.0f,
	//		matrix[0] * mat.matrix[12] + matrix[4] * mat.matrix[13] + matrix[8] * mat.matrix[14] + matrix[12], 
	//		matrix[1] * mat.matrix[12] + matrix[5] * mat.matrix[13] + matrix[9] * mat.matrix[14] + matrix[13],
	//		matrix[2] * mat.matrix[12] + matrix[6] * mat.matrix[13] + matrix[10] * mat.matrix[14] + matrix[14],
	//		1.0f
	//	);
	//} else {
	//	std::cout << "Nie mo¿na pomno¿yæ macierzy!" << std::endl;
	//	return Matrix4x4();
	//}
	return Matrix4x4(
		matrix[0 + 4 * 0] * other.matrix[0 + 4 * 0] + matrix[1 + 4 * 0] * other.matrix[0 + 4 * 1] + matrix[2 + 4 * 0] * other.matrix[0 + 4 * 2] + matrix[3 + 4 * 0] * other.matrix[0 + 4 * 3],
		matrix[0 + 4 * 0] * other.matrix[1 + 4 * 0] + matrix[1 + 4 * 0] * other.matrix[1 + 4 * 1] + matrix[2 + 4 * 0] * other.matrix[1 + 4 * 2] + matrix[3 + 4 * 0] * other.matrix[1 + 4 * 3],
		matrix[0 + 4 * 0] * other.matrix[2 + 4 * 0] + matrix[1 + 4 * 0] * other.matrix[2 + 4 * 1] + matrix[2 + 4 * 0] * other.matrix[2 + 4 * 2] + matrix[3 + 4 * 0] * other.matrix[2 + 4 * 3],
		matrix[0 + 4 * 0] * other.matrix[3 + 4 * 0] + matrix[1 + 4 * 0] * other.matrix[3 + 4 * 1] + matrix[2 + 4 * 0] * other.matrix[3 + 4 * 2] + matrix[3 + 4 * 0] * other.matrix[3 + 4 * 3],

		matrix[0 + 4 * 1] * other.matrix[0 + 4 * 0] + matrix[1 + 4 * 1] * other.matrix[0 + 4 * 1] + matrix[2 + 4 * 1] * other.matrix[0 + 4 * 2] + matrix[3 + 4 * 1] * other.matrix[0 + 4 * 3],
		matrix[0 + 4 * 1] * other.matrix[1 + 4 * 0] + matrix[1 + 4 * 1] * other.matrix[1 + 4 * 1] + matrix[2 + 4 * 1] * other.matrix[1 + 4 * 2] + matrix[3 + 4 * 1] * other.matrix[1 + 4 * 3],
		matrix[0 + 4 * 1] * other.matrix[2 + 4 * 0] + matrix[1 + 4 * 1] * other.matrix[2 + 4 * 1] + matrix[2 + 4 * 1] * other.matrix[2 + 4 * 2] + matrix[3 + 4 * 1] * other.matrix[2 + 4 * 3],
		matrix[0 + 4 * 1] * other.matrix[3 + 4 * 0] + matrix[1 + 4 * 1] * other.matrix[3 + 4 * 1] + matrix[2 + 4 * 1] * other.matrix[3 + 4 * 2] + matrix[3 + 4 * 1] * other.matrix[3 + 4 * 3],

		matrix[0 + 4 * 2] * other.matrix[0 + 4 * 0] + matrix[1 + 4 * 2] * other.matrix[0 + 4 * 1] + matrix[2 + 4 * 2] * other.matrix[0 + 4 * 2] + matrix[3 + 4 * 2] * other.matrix[0 + 4 * 3],
		matrix[0 + 4 * 2] * other.matrix[1 + 4 * 0] + matrix[1 + 4 * 2] * other.matrix[1 + 4 * 1] + matrix[2 + 4 * 2] * other.matrix[1 + 4 * 2] + matrix[3 + 4 * 2] * other.matrix[1 + 4 * 3],
		matrix[0 + 4 * 2] * other.matrix[2 + 4 * 0] + matrix[1 + 4 * 2] * other.matrix[2 + 4 * 1] + matrix[2 + 4 * 2] * other.matrix[2 + 4 * 2] + matrix[3 + 4 * 2] * other.matrix[2 + 4 * 3],
		matrix[0 + 4 * 2] * other.matrix[3 + 4 * 0] + matrix[1 + 4 * 2] * other.matrix[3 + 4 * 1] + matrix[2 + 4 * 2] * other.matrix[3 + 4 * 2] + matrix[3 + 4 * 2] * other.matrix[3 + 4 * 3],

		matrix[0 + 4 * 3] * other.matrix[0 + 4 * 0] + matrix[1 + 4 * 3] * other.matrix[0 + 4 * 1] + matrix[2 + 4 * 3] * other.matrix[0 + 4 * 2] + matrix[3 + 4 * 3] * other.matrix[0 + 4 * 3],
		matrix[0 + 4 * 3] * other.matrix[1 + 4 * 0] + matrix[1 + 4 * 3] * other.matrix[1 + 4 * 1] + matrix[2 + 4 * 3] * other.matrix[1 + 4 * 2] + matrix[3 + 4 * 3] * other.matrix[1 + 4 * 3],
		matrix[0 + 4 * 3] * other.matrix[2 + 4 * 0] + matrix[1 + 4 * 3] * other.matrix[2 + 4 * 1] + matrix[2 + 4 * 3] * other.matrix[2 + 4 * 2] + matrix[3 + 4 * 3] * other.matrix[2 + 4 * 3],
		matrix[0 + 4 * 3] * other.matrix[3 + 4 * 0] + matrix[1 + 4 * 3] * other.matrix[3 + 4 * 1] + matrix[2 + 4 * 3] * other.matrix[3 + 4 * 2] + matrix[3 + 4 * 3] * other.matrix[3 + 4 * 3]
	);
}

Matrix4x4 Matrix4x4::dot(const float& f)
{
	return Matrix4x4(
		matrix[0] * f,
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
		matrix[15] * f
	);
}

Matrix4x4 Matrix4x4::operator*(const float& f)
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
	float determinant;

	matrix[0] = 
		m.matrix[5] * m.matrix[10] * m.matrix[15] -
		m.matrix[5] * m.matrix[11] * m.matrix[14] -
		m.matrix[9] * m.matrix[6] * m.matrix[15] +
		m.matrix[9] * m.matrix[7] * m.matrix[14] +
		m.matrix[13] * m.matrix[6] * m.matrix[11] -
		m.matrix[13] * m.matrix[7] * m.matrix[10];

	matrix[4] = 
		-m.matrix[4] * m.matrix[10] * m.matrix[15] +
		m.matrix[4] * m.matrix[11] * m.matrix[14] +
		m.matrix[8] * m.matrix[6] * m.matrix[15] -
		m.matrix[8] * m.matrix[7] * m.matrix[14] -
		m.matrix[12] * m.matrix[6] * m.matrix[11] +
		m.matrix[12] * m.matrix[7] * m.matrix[10];

	matrix[8] = 
		m.matrix[4] * m.matrix[9] * m.matrix[15] -
		m.matrix[4] * m.matrix[11] * m.matrix[13] -
		m.matrix[8] * m.matrix[5] * m.matrix[15] +
		m.matrix[8] * m.matrix[7] * m.matrix[13] +
		m.matrix[12] * m.matrix[5] * m.matrix[11] -
		m.matrix[12] * m.matrix[7] * m.matrix[9];

	matrix[12] = 
		-m.matrix[4] * m.matrix[9] * m.matrix[14] +
		m.matrix[4] * m.matrix[10] * m.matrix[13] +
		m.matrix[8] * m.matrix[5] * m.matrix[14] -
		m.matrix[8] * m.matrix[6] * m.matrix[13] -
		m.matrix[12] * m.matrix[5] * m.matrix[10] +
		m.matrix[12] * m.matrix[6] * m.matrix[9];

	matrix[1] = 
		-m.matrix[1] * m.matrix[10] * m.matrix[15] +
		m.matrix[1] * m.matrix[11] * m.matrix[14] +
		m.matrix[9] * m.matrix[2] * m.matrix[15] -
		m.matrix[9] * m.matrix[3] * m.matrix[14] -
		m.matrix[13] * m.matrix[2] * m.matrix[11] +
		m.matrix[13] * m.matrix[3] * m.matrix[10];

	matrix[5] = 
		m.matrix[0] * m.matrix[10] * m.matrix[15] -
		m.matrix[0] * m.matrix[11] * m.matrix[14] -
		m.matrix[8] * m.matrix[2] * m.matrix[15] +
		m.matrix[8] * m.matrix[3] * m.matrix[14] +
		m.matrix[12] * m.matrix[2] * m.matrix[11] -
		m.matrix[12] * m.matrix[3] * m.matrix[10];

	matrix[9] = 
		-m.matrix[0] * m.matrix[9] * m.matrix[15] +
		m.matrix[0] * m.matrix[11] * m.matrix[13] +
		m.matrix[8] * m.matrix[1] * m.matrix[15] -
		m.matrix[8] * m.matrix[3] * m.matrix[13] -
		m.matrix[12] * m.matrix[1] * m.matrix[11] +
		m.matrix[12] * m.matrix[3] * m.matrix[9];

	matrix[13] = 
		m.matrix[0] * m.matrix[9] * m.matrix[14] -
		m.matrix[0] * m.matrix[10] * m.matrix[13] -
		m.matrix[8] * m.matrix[1] * m.matrix[14] +
		m.matrix[8] * m.matrix[2] * m.matrix[13] +
		m.matrix[12] * m.matrix[1] * m.matrix[10] -
		m.matrix[12] * m.matrix[2] * m.matrix[9];

	matrix[2] =
		m.matrix[1] * m.matrix[6] * m.matrix[15] -
		m.matrix[1] * m.matrix[7] * m.matrix[14] -
		m.matrix[5] * m.matrix[2] * m.matrix[15] +
		m.matrix[5] * m.matrix[3] * m.matrix[14] +
		m.matrix[13] * m.matrix[2] * m.matrix[7] -
		m.matrix[13] * m.matrix[3] * m.matrix[6];

	matrix[6] = 
		-m.matrix[0] * m.matrix[6] * m.matrix[15] +
		m.matrix[0] * m.matrix[7] * m.matrix[14] +
		m.matrix[4] * m.matrix[2] * m.matrix[15] -
		m.matrix[4] * m.matrix[3] * m.matrix[14] -
		m.matrix[12] * m.matrix[2] * m.matrix[7] +
		m.matrix[12] * m.matrix[3] * m.matrix[6];

	matrix[10] = 
		m.matrix[0] * m.matrix[5] * m.matrix[15] -
		m.matrix[0] * m.matrix[7] * m.matrix[13] -
		m.matrix[4] * m.matrix[1] * m.matrix[15] +
		m.matrix[4] * m.matrix[3] * m.matrix[13] +
		m.matrix[12] * m.matrix[1] * m.matrix[7] -
		m.matrix[12] * m.matrix[3] * m.matrix[5];

	matrix[14] = 
		-m.matrix[0] * m.matrix[5] * m.matrix[14] +
		m.matrix[0] * m.matrix[6] * m.matrix[13] +
		m.matrix[4] * m.matrix[1] * m.matrix[14] -
		m.matrix[4] * m.matrix[2] * m.matrix[13] -
		m.matrix[12] * m.matrix[1] * m.matrix[6] +
		m.matrix[12] * m.matrix[2] * m.matrix[5];

	matrix[3] = 
		-m.matrix[1] * m.matrix[6] * m.matrix[11] +
		m.matrix[1] * m.matrix[7] * m.matrix[10] +
		m.matrix[5] * m.matrix[2] * m.matrix[11] -
		m.matrix[5] * m.matrix[3] * m.matrix[10] -
		m.matrix[9] * m.matrix[2] * m.matrix[7] +
		m.matrix[9] * m.matrix[3] * m.matrix[6];

	matrix[7] =
		m.matrix[0] * m.matrix[6] * m.matrix[11] -
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

	matrix[15] = 
		m.matrix[0] * m.matrix[5] * m.matrix[10] -
		m.matrix[0] * m.matrix[6] * m.matrix[9] -
		m.matrix[4] * m.matrix[1] * m.matrix[10] +
		m.matrix[4] * m.matrix[2] * m.matrix[9] +
		m.matrix[8] * m.matrix[1] * m.matrix[6] -
		m.matrix[8] * m.matrix[2] * m.matrix[5];

	determinant = m.matrix[0] * matrix[0] + m.matrix[1] * matrix[4] + m.matrix[2] * matrix[8] + m.matrix[3] * matrix[12];

	if (determinant == 0)
		return false;

	determinant = 1.0f / determinant;
	
	for (int i = 0; i < 16; i++)
		matrix[i] = matrix[i] * determinant;

	return true;
}

Matrix4x4 Matrix4x4::getInverse()
{
	Matrix4x4 res;
	res.invertMatrix(*this);
	return res;
}

void Matrix4x4::invertThis()
{
	invertMatrix(*this);
}

void Matrix4x4::transposeMatrix(const Matrix4x4& other)
{
	matrix[0]	= other.matrix[0];
	matrix[4]	= other.matrix[1];
	matrix[8]	= other.matrix[2];
	matrix[12]	= other.matrix[3];
	matrix[1]	= other.matrix[4];
	matrix[5]	= other.matrix[5];
	matrix[9]	= other.matrix[6];
	matrix[13]	= other.matrix[7];
	matrix[2]	= other.matrix[8];
	matrix[6]	= other.matrix[9];
	matrix[10]	= other.matrix[10];
	matrix[14]	= other.matrix[11];
	matrix[3]	= other.matrix[12];
	matrix[7]	= other.matrix[13];
	matrix[11]	= other.matrix[14];
	matrix[15]	= other.matrix[15];
}

Matrix4x4 Matrix4x4::transposeThis()
{
	Matrix4x4 res;
	res.transposeMatrix(*this);
	return res;
}

void Matrix4x4::translate(const Vector& position)
{
	matrix[12] = position.x;
	matrix[13] = position.y;
	matrix[14] = position.z;
}

void Matrix4x4::scale(const Vector& scale)
{
	loadIdentity();
	matrix[0] = scale.x;
	matrix[5] = scale.y;
	matrix[10] = scale.z;
}

void Matrix4x4::uniformScale(const float& scaleFactor)
{
	loadIdentity();
	matrix[0] = matrix[5] = matrix[10] = scaleFactor;
}

void Matrix4x4::setRotationAxis(const double& angle, const Vector& axis)
{
	Vector u = axis;
	u.normalize();

	float mySin = (float)sin(Constants::pi<double> * angle / 180);
	float myCos = (float)cos(Constants::pi<double> * angle / 180);

	loadIdentity();

	matrix[0] = u.x * u.x + myCos * (1.0f - u.x * u.x);
	matrix[4] = u.x * u.y * (1.0f - myCos) - mySin * u.z;
	matrix[8] = u.x * u.z * (1.0f - myCos) + mySin * u.y;

	matrix[1] = u.x * u.y * (1.0f - myCos) + mySin * u.z;
	matrix[5] = u.y * u.y + myCos * (1.0f - u.y * u.y);
	matrix[9] = u.y * u.z * (1.0f - myCos) - mySin * u.x;

	matrix[2] = u.x * u.z * (1.0f - myCos) - mySin * u.y;
	matrix[6] = u.y * u.z * (1.0f - myCos) + mySin * u.x;
	matrix[10] = u.z * u.z + myCos * (1.0f - u.z * u.z);
}

void Matrix4x4::rotateX(const double& angle)
{
	loadIdentity();

	matrix[5] = (float)cos(Constants::pi<double> * angle / 180);
	matrix[6] = (float)sin(Constants::pi<double> * angle / 180);

	matrix[9]  = -matrix[6];
	matrix[10] =  matrix[5];
}

void Matrix4x4::rotateY(const double& angle)
{
	loadIdentity();

	matrix[0] =  (float)cos(Constants::pi<double> * angle / 180);
	matrix[2] = -(float)sin(Constants::pi<double> * angle / 180);

	matrix[8]  = -matrix[2];
	matrix[10] =  matrix[0];
}

void Matrix4x4::rotateZ(const double& angle)
{
	loadIdentity();

	matrix[0] = (float)cos(Constants::pi<double> * angle / 180);
	matrix[1] = (float)sin(Constants::pi<double> * angle / 180);

	matrix[4] = -matrix[1];
	matrix[5] =  matrix[0];
}

std::string Matrix4x4::toString() {
	std::string temp;
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			temp += std::to_string(matrix[y + x * 4]);
			temp += ", ";
		}
		temp += '\n';
	}
	return temp;
}

Matrix3x3::Matrix3x3() : matrix { 0 } {}

Matrix3x3::Matrix3x3(
	// float e0, float e3, float e6, 
	// float e1, float e4, float e7, 
	// float e2, float e5, float e8
	const float& e0, const float& e1, const float& e2,
	const float& e3, const float& e4, const float& e5,
	const float& e6, const float& e7, const float& e8
) : matrix { e0, e1, e2, e3, e4, e5, e6, e7, e8 } {}

Matrix3x3::~Matrix3x3()
{
}
