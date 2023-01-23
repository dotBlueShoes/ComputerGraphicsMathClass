#include "Vector.hpp"

// Constructors

constexpr Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

constexpr Vector::Vector(const float& x, const float& y, const float& z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

constexpr Vector::Vector(const Vector& p1, const Vector& p2)
{
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
	this->z = p2.z - p1.z;
}

Vector& Vector::operator=(const Vector& other) {
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

void Vector::add(const float& value) 
{
	this->x += value;
	this->y += value;
	this->z += value;
}

void Vector::operator+=(const float& value) { add(value); }

Vector Vector::operator+(const float& other) const {
	float newX = this->x + other;
	float newY = this->y + other;
	float newZ = this->z + other;
	return Vector(newX, newY, newZ);
}

void Vector::subtract(const float& value) 
{
	this->x -= value;
	this->y -= value;
	this->z -= value;
}

void Vector::operator-=(const float& value) { subtract(value); }

Vector Vector::operator-(const float& other) const {
	float newX = this->x - other;
	float newY = this->y - other;
	float newZ = this->z - other;
	return Vector(newX, newY, newZ);
}

constexpr void Vector::divide(const float& value) {
	if (value != 0) {
		this->x /= value;
		this->y /= value;
		this->z /= value;
	} else {
		std::cout << "Can't divide by 0 [div]" << std::endl;
	}
}

void Vector::operator/=(const float& other) { divide(other); }

Vector Vector::operator/(const float& other) const {
	float newX = this->x / other;
	float newY = this->y / other;
	float newZ = this->z / other;
	return Vector(newX, newY, newZ);
}

void Vector::multiply(const float& value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

void Vector::operator*=(const float& other) { multiply(other); }

Vector Vector::operator*(const float& other) const {
	float newX = this->x * other;
	float newY = this->y * other;
	float newZ = this->z * other;
	return Vector(newX, newY, newZ);
}

void Vector::add(const Vector& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector::operator+=(const Vector& other) { add(other); }

Vector Vector::operator+(const Vector& other) const {
	float newX = this->x + other.x;
	float newY = this->y + other.y;
	float newZ = this->z + other.z;
	return Vector(newX, newY, newZ);
}

void Vector::subtract(const Vector& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

void Vector::operator-=(const Vector& other) { subtract(other); }

Vector Vector::operator-(const Vector& other) const {
	float newX = this->x - other.x;
	float newY = this->y - other.y;
	float newZ = this->z - other.z;
	return Vector(newX, newY, newZ);
}

float Vector::length() const
{
	return (float)(sqrt(
		(this->x * this->x) +
		(this->y * this->y) +
		(this->z * this->z)
	));
}

Vector Vector::normalize()
{
	const float length = this->length();
	if (length == 0)
		return Vector(0, 0, 0);

	return *this / length;

	//if (length != 0)
	//{
	//	this->divide(length);
	//} else
	//{
	//	std::cout << "Can't divide by 0 [normalize]" << std::endl;
	//}
}

float Vector::dot(const Vector& other) const
{
	const Vector result = {
		this->x * other.x,
		this->y * other.y,
		this->z * other.z
	};

	return (result.x + result.y + result.z);
}

Vector Vector::cross(const Vector& other) const
{
	return Vector(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

void Vector::operator*=(const Vector& other)
{
	this->x = this->y * other.z - this->z * other.y;
	this->y = this->z * other.x - this->x * other.z;
	this->z = this->x * other.y - this->y * other.x;
}

Vector Vector::operator*(const Vector& other) const {
	return Vector(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

Vector Vector::operator/(const Vector& v) const
{
	Vector newV = v;
	if (newV.x == 0)
	{
		newV.x = 1;
	}

	if (newV.y == 0)
	{
		newV.y = 1;
	}

	if (newV.z == 0)
	{
		newV.z = 1;
	}

	Vector res;
	res.x = this->x / newV.x;
	res.y = this->y / newV.y;
	res.z = this->z / newV.z;

	return res;
}

Vector Vector::min(Vector v1, Vector v2)
{
	Vector res;
	res.x = std::min(v1.x, v2.x);
	res.y = std::min(v1.y, v2.y);
	res.z = std::min(v1.z, v2.z);
	return res;
}

Vector Vector::max(Vector v1, Vector v2)
{
	Vector res;
	res.x = std::max(v1.x, v2.x);
	res.y = std::max(v1.y, v2.y);
	res.z = std::max(v1.z, v2.z);
	return res;
}

float Vector::angle(const Vector& other)
{
	// eg.
	// u * v = u.x * v.x + u.x * v.x + u.x * v.x
	// u * v = u.length * v.length * cos(angle)
	// => cos(angle) = u.x * v.x + u.x * v.x + u.x * v.x / (u.length * v.length)
	return acos(this->dot(other) / (this->length() * other.length()));
}

bool Vector::isClose(Vector& other, float error)
{
	return std::abs(this->length() - other.length()) < error;
}

std::string Vector::toString() {
	std::string temp("Vector: ");
	temp += std::to_string(this->x);
	temp += ", ";
	temp += std::to_string(this->y);
	temp += ", ";
	temp += std::to_string(this->z);
	temp += ". ";
	return temp;
}