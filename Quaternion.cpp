#include "Quaternion.hpp"

Quaternion& Quaternion::operator=(const Quaternion& other) {
	this->scalar = other.scalar;
	this->vector = other.vector;
	return *this;
}

Quaternion Quaternion::add(const Quaternion& other) {
	float tempScalar = this->scalar + other.scalar;
	Vector imaginary = this->vector + other.vector;
	return Quaternion(tempScalar, imaginary);
}

void Quaternion::operator+=(const Quaternion& other) {
	this->scalar += other.scalar;
	this->vector += other.vector;
}

Quaternion Quaternion::operator+(const Quaternion& other) const {
    float tempScalar = this->scalar + other.scalar;
    Vector imaginary = this->vector + other.vector;
    return Quaternion(tempScalar, imaginary);
}

Quaternion Quaternion::sub(const Quaternion& other) {
	float tempScalar = this->scalar - other.scalar;
	Vector imaginary = vector - other.vector;
	return Quaternion(tempScalar, imaginary);
}

void Quaternion::operator-=(const Quaternion& other) {
    this->scalar -= other.scalar;
    this->vector -= other.vector;
}

Quaternion Quaternion::operator-(const Quaternion& other) const {
    float tempScalar = this->scalar - other.scalar;
    Vector imaginary = vector - other.vector;
    return Quaternion(tempScalar, imaginary);
}

Quaternion Quaternion::mul(const Quaternion& other) const {
	float tempScalar = this->scalar * other.scalar - this->vector.dot(other.vector);
	Vector imaginary = (other.vector * this->scalar) + (this->vector * other.scalar) + this->vector.cross(other.vector);
	return Quaternion(tempScalar, imaginary);
}

Quaternion Quaternion::operator*(const Quaternion& other)const {
	float tempScalar = this->scalar * other.scalar - this->vector.dot(other.vector);
	Vector imaginary = (other.vector * this->scalar) + (this->vector * other.scalar) + this->vector.cross(other.vector);
	return Quaternion(tempScalar, imaginary);
}

void Quaternion::operator*=(const Quaternion& other) {
	(*this) = mul(other);
}

Quaternion Quaternion::div(Quaternion other) const {
	Quaternion product = other.inverse();
	float tempScalar = this->scalar * product.scalar - this->vector.dot(product.vector);
	Vector imaginary = (product.vector * this->scalar) + (this->vector * product.scalar) + this->vector.cross(product.vector);
	return Quaternion(tempScalar, imaginary);
}

void Quaternion::operator/=(Quaternion other) {
	(*this) = div(other);
}

Quaternion Quaternion::operator/(Quaternion other) const {
	Quaternion product = other.inverse();
	//std::cout << product.toString() << "\n";
	float tempScalar = this->scalar * product.scalar - this->vector.dot(product.vector);
	Vector imaginary = (product.vector * this->scalar) + (this->vector * product.scalar) + this->vector.cross(product.vector);
	return Quaternion(tempScalar, imaginary);
}

float Quaternion::norm() {
	float tempScalar = this->scalar * this->scalar;
	float imaginary = this->vector.dot(this->vector);
	return sqrt(tempScalar + imaginary);
}

void Quaternion::normalize() {
	if (norm() != 0) {
		float normValue = 1 / norm();
		this->scalar *= normValue;
		this->vector *= normValue;
	}
}

void Quaternion::convertToUnitNormQuaternion() {
	float angle = this->scalar * Constants::pi<float> / 180;
	this->vector = this->vector.normalize();
	this->scalar = cosf(angle * 0.5);
	this->vector = this->vector * sinf(angle * 0.5);
}

Quaternion Quaternion::conjugate() {
	float tempScalar = this->scalar;
	Vector imaginary = this->vector * (-1);
	return Quaternion(tempScalar, imaginary);
}

Quaternion Quaternion::inverse() {
	float absoluteValue = norm();
	absoluteValue *= absoluteValue;
	absoluteValue = 1 / absoluteValue;

	Quaternion conjugateValue = conjugate();
	float tempScalar = conjugateValue.scalar * absoluteValue;
	Vector imaginary = conjugateValue.vector * absoluteValue;

	return Quaternion(tempScalar, imaginary);
}

Vector Quaternion::rotateVectorAboutAngleAndAxis(const float& angle, Vector& axis) {
	Quaternion startVector(0, this->vector); // Convert our vector to a pure quaternion
	axis = axis.normalize(); // Normalize the axis
	//std::cout << "here: " << axis.toString();
	Quaternion temp(angle , axis); // Create the real quaternion
	temp.convertToUnitNormQuaternion(); // Convert quaternion to unit norm quaternion
	Quaternion qInverse = temp.inverse(); // Get the inverse of the quaternion
	Quaternion rotatedVector = temp * startVector * qInverse; // Rotate the quaternion
	return rotatedVector.vector; // Return the vector part of the quaternion
}

std::string Quaternion::toString() {
	std::string temp("Quaternion: ");
	temp += std::to_string(this->scalar);
	temp += ", ";
	temp += this->vector.toString();
	temp += ". ";
	return temp;
}