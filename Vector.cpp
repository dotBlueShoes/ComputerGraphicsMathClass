#include "Vector.h"

Vector::Vector()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector::Vector(Vector p1, Vector p2)
{
	this->x = p2.x - p1.x;
	this->y = p2.y - p1.y;
	this->z = p2.z - p1.z;
}

Vector::~Vector()
{
}

void Vector::add(Vector v)
{
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;
}

void Vector::sub(Vector v)
{
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;
}

void Vector::div(float f)
{
	if (f != 0)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
	}
	else
	{
		std::cout << "Can't divide by 0 [div]" << std::endl;
	}
}

void Vector::mul(float f)
{
	this->x *= f;
	this->y *= f;
	this->z *= f;
}

float Vector::length()
{
	float length = (float)sqrt((this->x * this->x) +
		(this->y * this->y) +
		(this->z * this->z));

	return length;
}

void Vector::normalize()
{
	float len = this->length();
	if (len != 0)
	{
		this->div(len);
	}
	else
	{
		std::cout << "Can't divide by 0 [normalize]" << std::endl;
	}
}

Vector Vector::dot(Vector v)
{
	Vector f;
	f.x = this->x * v.x;
	f.y = this->y * v.y;
	f.z = this->z * v.z;
	return f;
}

float Vector::dotProduct(Vector v)
{
	Vector f = this->dot(v);
	return f.x + f.y + f.z;
}

Vector Vector::cross(Vector v)
{
	return Vector(this->y * v.z - this->z * v.y,
		this->z * v.x - this->x * v.z,
		this->x * v.y - this->y * v.x);
}

float Vector::angle(Vector v)
{
	return this->dotProduct(v) / (this->length() * v.length());
}
