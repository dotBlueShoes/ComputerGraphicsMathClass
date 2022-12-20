#pragma once
#include "Framework.hpp"
#include "Constants.hpp"

struct Vector
{
	float x { 0 }, y { 0 }, z { 0 };

	// Constructors
	constexpr Vector();
	constexpr Vector(const float&, const float&, const float&);

	constexpr Vector(const Vector& other) {
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	constexpr Vector(const Vector&, const Vector&);

	Vector& operator=(const Vector&);

	constexpr bool operator==(const Vector& other) const {
		return {
			this->x == other.x &&
			this->y == other.y &&
			this->z == other.z
		};
	}

	constexpr bool operator!=(const Vector& other) const {
		return !(
			this->x == other.x &&
			this->y == other.y &&
			this->z == other.z
		);
	}

	float length() const;			
	void normalize();		// Transform vector to (-1 : 1) range.
	float angle(const Vector&);	// Angle between two vectors

	// Scalar Operations
	void add(const float&);
	void operator+=(const float&);
	Vector operator+(const float&) const;
	void subtract(const float&);
	void operator-=(const float&);
	Vector operator-(const float&) const;
	constexpr void divide(const float&);
	void operator/=(const float&);
	Vector operator/(const float&) const;
	void multiply(const float&);
	void operator*=(const float&);
	Vector operator*(const float&) const;
	float dot(const Vector&) const;

	// Vector Operations
	void add(const Vector&);
	void operator+=(const Vector&);
	Vector operator+(const Vector&) const;
	void subtract(const Vector&);
	void operator-=(const Vector&);
	Vector operator-(const Vector&) const;
	Vector cross(const Vector&) const;	 // Iloczyn krzy¿owy daje wektor prostopad³y do wektorów mno¿enia i mno¿nika.
	void operator*=(const Vector&);
	Vector operator*(const Vector&) const;

	std::string toString();
	
};