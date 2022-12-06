#pragma once
#include "Vector.hpp"

struct Quaternion {
	
	Vector vector;
	float scalar;

	Quaternion() {
		this->scalar = 0;
		this->vector.x = 0;
		this->vector.y = 0;
		this->vector.z = 0;
	}

	Quaternion(const float& newScalar, const Vector& newVector) : scalar(newScalar), vector(newVector) {}

	//Quaternion(const Quaternion& other) {
	//	this->scalar = other.scalar;
	//	this->vector = other.vector;
	//}

	Quaternion& operator=(const Quaternion& other);

	~Quaternion() {}

	constexpr bool operator==(const Quaternion& other) const {
		return {
			this->scalar == other.scalar &&
			this->vector == other.vector
		};
	}

	constexpr bool operator!=(const Quaternion& other) const {
		return !(
			this->scalar == other.scalar &&
			this->vector == other.vector
		);
	}
	
	Quaternion add(const Quaternion& other);
	void operator+=(const Quaternion& other);
	Quaternion operator+(const Quaternion& other) const;
	
	Quaternion sub(const Quaternion& other);
	void operator-=(const Quaternion& other);
	Quaternion operator-(const Quaternion& other) const;
	
	Quaternion mul(const Quaternion& other) const;
	void operator*=(const Quaternion& other);
	Quaternion operator*(const Quaternion& other) const;

	Quaternion div(Quaternion other) const;
	void operator/=(Quaternion other);
	Quaternion operator/(Quaternion other) const;

	float norm();
	void normalize();
	void convertToUnitNormQuaternion();
	Quaternion conjugate();
	Quaternion inverse();
	Vector rotateVectorAboutAngleAndAxis(const float& angle, Vector& axis);

	// to-euler

	std::string toString();

};