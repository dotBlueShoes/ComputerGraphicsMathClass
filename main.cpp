#include <iostream>
#include <fstream>
#include <math.h>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

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

int main() {
	//std::ofstream file("result.txt");

	//{ // 2. Sprawdź czy działa przemienność dodawania.
	//	Vector v1(-2, 4, -9);
	//	Vector v2(5, -3, 34);
	//	Vector res1 = v1;
	//	res1.add(v2);
	//	Vector res2 = v2;
	//	res2.add(v1);

	//	if (res1.x == res2.x && res1.y == res2.y && res1.z == res2.z) {
	//		file << "Commutation of addition is working." << std::endl;
	//	} else {
	//		file << "Commutation of addition is not working." << std::endl;
	//	}
	//}
	//
	//{ // 3. Znajdź kąt pomiędzy wektorem.
	//	Vector v3(0, 3, 0);
	//	Vector v4(5, 5, 0);

	//	// Due to PI we're not getting a clear 45deg
	//	float angle = v3.angle(v4) * 180.0f / M_PI;

	//	file << "3. " << angle << std::endl;
	//}
	//
	//{ // 4. Znajdź wektor prostopadły do wektorów.
	//	Vector v5(4, 5, 1);
	//	Vector v6(4, 1, 3);

	//	Vector cross = v5.cross(v6);

	//	file << "4. [" << cross.x << ", " << cross.y << ", " << cross.z << "]" << std::endl;
	//	{ // 5. Znormalizuj powstały wektor.
	//		cross.normalize();

	//		file << "5. [" << cross.x << ", " << cross.y << ", " << cross.z << "]" << std::endl;

	//		file.close();
	//	}
	//}

	// 2. Sprawdź czy prawidłowo działają wszystkie operacje, wyniki sprawdzeń zapisz w dokumencie word.
	
	// Dodawanie i odejmowanie macierzy.
	// Mnożenie przez skalar.
	// Mnożenie macierzy przez macierz
	// Macierz jednostkowa
	// Macierz odwrotna transponowana
	// Tlanslacja
	// Skalowanie
	// Obrót X, Y, Z
	// Składowanie przekształceń

	float f = 2.0f;
	Matrix4x4 test1(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	Matrix4x4 test2(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	Matrix4x4 addres(15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15);
	Matrix4x4 subres(-15, -13, -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11, 13, 15);
	//Matrix4x4 mulres(304, 358, 412, 466, 208, 246, 284, 322, 112, 134, 156, 178, 16, 22, 28, 34);
	Matrix4x4 mulres(34, 28, 22, 16, 178, 156, 134, 112, 322, 284, 246, 208, 466, 412, 358, 304);
	Matrix4x4 dotres(0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
	Matrix4x4 identity(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
	Matrix4x4 identity2;
	identity2.loadIdentity();
	Matrix4x4 inv(1, 2, 1, 1, 2, 3, 1, 0, 3, 1, 1, -2, 4, 2, -1, -6);
	Matrix4x4 invcheck(22, -17, -1, 4, -6, 5, 0, -1, -26, 20, 2, -5, 17, -13, -1, 3);
	Matrix4x4 transcheck(0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15);

	if (test1.add(test2) == addres)
		std::cout << "Addition works!" << std::endl;
	else
		std::cout << "Addition doesn't work :(" << std::endl;
	
	if (test1.subtract(test2) == subres)
		std::cout << "Subtraction works!" << std::endl;
	else
		std::cout << "Subtraction doesn't work :(" << std::endl;
	
	if (test1.multiply(test2) == mulres)
		std::cout << "Multiplication works!" << std::endl;
	else
		std::cout << "Multiplication doesn't work :(" << std::endl;
	
	if (test1.dot(f) == dotres)
		std::cout << "Scalar multiplication works!" << std::endl;
	else
		std::cout << "Scalar multiplication doesn't work :(" << std::endl;
	
	if (identity2 == identity)
		std::cout << "Identity works!" << std::endl;
	else
		std::cout << "Identity doesn't work :(" << std::endl;
	
	if (inv.getInverse() == invcheck)
		std::cout << "Inversion works!" << std::endl;
	else
		std::cout << "Inversion doesn't work :(" << std::endl;
	
	if (test1.transposeThis() == transcheck)
		std::cout << "Transposition works!" << std::endl;
	else
		std::cout << "Transposition doesn't work :(" << std::endl;

	

	{ // 3. Wektor [1001] , obróć o 90 stopni wokół osi Y
		Matrix4x4 vectorAsMatrix(1, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  1, 0, 0, 0);
		Matrix4x4 rotateY = Matrix4x4();
		rotateY.rotateY(90);

		std::string temp = "Vector:\n";
		temp += vectorAsMatrix.toString();
		temp += "Rotation matrix:\n";
		temp += rotateY.toString();

		Matrix4x4 result = rotateY.multiply(vectorAsMatrix);
		temp += "Result matrix:\n";
		temp += result.toString();

		std::cout << temp;
	}
	
	{ // 4. Wykaż za pomocą zaimplementowanego przykładu braku przemienności mnożenia macierzy
		Matrix4x4 test3(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		if (test2.multiply(test3) == mulres)
			std::cout << "Multiplication works :( !" << std::endl;
		else
			std::cout << "Multiplication doesn't work :)" << std::endl;
	}
	

	return 0;
}