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

void Vector::add(const float& value) 
{
	this->x += value;
	this->y += value;
	this->z += value;
}

void Vector::operator+=(const float& value) { add(value); }

void Vector::subtract(const float& value) 
{
	this->x -= value;
	this->y -= value;
	this->z -= value;
}

void Vector::operator-=(const float& value) { subtract(value); }

void Vector::divide(const float& value) {
	if (value != 0) {
		this->x /= value;
		this->y /= value;
		this->z /= value;
	} else {
		std::cout << "Can't divide by 0 [div]" << std::endl;
	}
}

void Vector::operator/=(const float& other) { divide(other); }

void Vector::multiply(const float& value) {
	this->x *= value;
	this->y *= value;
	this->z *= value;
}

void Vector::operator*=(const float& other) { multiply(other); }

void Vector::add(const Vector& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector::operator+=(const Vector& other) { add(other); }

void Vector::subtract(const Vector& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

void Vector::operator-=(const Vector& other) { subtract(other); }

float Vector::length()
{
	return (float)(sqrt(
		(this->x * this->x) +
		(this->y * this->y) +
		(this->z * this->z)
	));
}

void Vector::normalize()
{
	const float length = this->length();
	if (length != 0)
	{
		this->divide(length);
	} else
	{
		std::cout << "Can't divide by 0 [normalize]" << std::endl;
	}
}

Vector Vector::dot(const Vector& other)
{
	return { 
		this->x * other.x,
		this->y * other.y,
		this->z * other.z
	};
}

float Vector::dotProduct(const Vector& other)
{
	const Vector result = this->dot(other);
	return result.x + result.y + result.z;
}

Vector Vector::cross(const Vector& other)
{
	return Vector(
		this->y * other.z - this->z * other.y,
		this->z * other.x - this->x * other.z,
		this->x * other.y - this->y * other.x
	);
}

float Vector::angle(Vector& other)
{
	// eg.
	// u * v = u.x * v.x + u.x * v.x + u.x * v.x
	// u * v = u.length * v.length * cos(angle)
	// => cos(angle) = u.x * v.x + u.x * v.x + u.x * v.x / (u.length * v.length)
	return acos(this->dotProduct(other) / (this->length() * other.length()));
}
