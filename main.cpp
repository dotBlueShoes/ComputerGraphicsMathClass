﻿#include <iostream>
#include <fstream>
#include <math.h>

#include "Framework.hpp"
#include "Vector.h"

// TODO
// Zaimplementuj klasę wektor wraz ze wszystkimi działaniami.
// Sprawdź czy prawidłowo działa przemienność dodawania za pomocą odpowiedniego zdefiniowania przykładowych wektorów i ich sumy w funkcji main().
// 
// Znajdź kąt pomiędzy wektorem[0, 3, 0] a[5, 5, 0]
// 
// Znajdź wektor prostopadły do wektorów[4, 5, 1] i[4, 1, 3]
// 
// Znormalizuj powstały wektor
//

template <class T>
struct Vector2 {
	T x, y;
};

ErrorType function() {
	return ErrorCode::Success;
}

int main() {
	//Vector2<float> sample { 0, 0 };

	std::ofstream file("result.txt");

	Vector v1(-2, 4, -9);
	Vector v2(5, -3, 34);
	Vector res1 = v1;
	res1.add(v2);
	Vector res2 = v2;
	res2.add(v1);

	if (res1.x == res2.x && res1.y == res2.y && res1.z == res2.z)
	{
		file << "Commutation of addition is working." << std::endl;
	}
	else
	{
		file << "Commutation of addition is not working." << std::endl;
	}

	Vector v3(0, 3, 0);
	Vector v4(5, 5, 0);

	float angle = acos(v3.angle(v4)) * 180 / 3.14;
	std::cout << angle;

	file << "3. " << angle << std::endl;

	Vector v5(4, 5, 1);
	Vector v6(4, 1, 3);

	Vector cross = v5.cross(v6);

	file << "4. [" << cross.x << ", " << cross.y << ", " << cross.z << "]" << std::endl;

	cross.normalize();

	file << "5. [" << cross.x << ", " << cross.y << ", " << cross.z << "]" << std::endl;

	file.close();

	return (int)(ErrorCode::Success);
}