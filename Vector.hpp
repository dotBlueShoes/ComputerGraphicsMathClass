#pragma once
#include "Framework.hpp"
#include "Constants.hpp"

struct Vector
{
	float x { 0 }, y { 0 }, z { 0 };

	// Constructors
	constexpr Vector();
	constexpr Vector(const float&, const float&, const float&);
	constexpr Vector(const Vector&, const Vector&);

	float length();			
	void normalize();		// Transform vector to (-1 : 1) range.
	float angle(Vector&);	// Angle between two vectors

	// Scalar Operations
	void add(const float&);
	void operator+=(const float&);
	void subtract(const float&);
	void operator-=(const float&);
	void divide(const float&);
	void operator/=(const float&);
	void multiply(const float&);
	void operator*=(const float&);
	Vector dot(const Vector&);		 //
	float dotProduct(const Vector&); // Iloczyn Skalarny jest operacj¹ na wektorach, która oblicza k¹t pomiêdzy dwoma wektorami.

	// Vector Operations
	void add(const Vector&);
	void operator+=(const Vector&);
	void subtract(const Vector&);
	void operator-=(const Vector&);
	Vector cross(const Vector&);	 // Iloczyn krzy¿owy daje wektor prostopad³y do wektorów mno¿enia i mno¿nika.

	
};