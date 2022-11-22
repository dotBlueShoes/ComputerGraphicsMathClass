#include <iostream>
#include <fstream>
#include <math.h>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

int main() {

	// 2. Sprawdź czy prawidłowo działają wszystkie operacje, wyniki sprawdzeń zapisz w dokumencie word.
	
	Matrix4x4 test1(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	Matrix4x4 test2(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	float scalar = 2.0f;

	
	
	{ // - Dodawanie i odejmowanie macierzy.
		Matrix4x4 addres(15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15);
		Matrix4x4 subres(-15, -13, -11, -9, -7, -5, -3, -1, 1, 3, 5, 7, 9, 11, 13, 15);

		if (test1.add(test2) == addres)
			std::cout << "Addition works!" << std::endl;
		else
			std::cout << "Addition doesn't work :(" << std::endl;

		if (test1.subtract(test2) == subres)
			std::cout << "Subtraction works!" << std::endl;
		else
			std::cout << "Subtraction doesn't work :(" << std::endl;
	}

	
	{ // - Mnożenie macierzy przez macierz
		Matrix4x4 mulres(34, 28, 22, 16, 178, 156, 134, 112, 322, 284, 246, 208, 466, 412, 358, 304);
		if (test1.multiply(test2) == mulres)
			std::cout << "Multiplication works!" << std::endl;
		else
			std::cout << "Multiplication doesn't work :(" << std::endl;
	}
	
	
	{ // - Mnożenie przez skalar.
		Matrix4x4 dotres(0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30);
		if (test1.dot(scalar) == dotres)
			std::cout << "Scalar multiplication works!" << std::endl;
		else
			std::cout << "Scalar multiplication doesn't work :(" << std::endl;
	}

	{ // - Macierz jednostkowa
		Matrix4x4 identity(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		Matrix4x4 identity2;
		identity2.loadIdentity();

		if (identity2 == identity)
			std::cout << "Identity works!" << std::endl;
		else
			std::cout << "Identity doesn't work :(" << std::endl;
	}

	{ // - Macierz odwrotna transponowana
		Matrix4x4 inv(1, 2, 1, 1, 2, 3, 1, 0, 3, 1, 1, -2, 4, 2, -1, -6);
		Matrix4x4 invcheck(22, -17, -1, 4, -6, 5, 0, -1, -26, 20, 2, -5, 17, -13, -1, 3);

		if (inv.getInverse() == invcheck)
			std::cout << "Inversion works!" << std::endl;
		else
			std::cout << "Inversion doesn't work :(" << std::endl;
	}

	{ // - Translacja
		Matrix4x4 transcheck(0, 4, 8, 12, 1, 5, 9, 13, 2, 6, 10, 14, 3, 7, 11, 15);
		if (test1.transposeThis() == transcheck)
			std::cout << "Transposition works!" << std::endl;
		else
			std::cout << "Transposition doesn't work :(" << std::endl;
	}

	{
		Matrix4x4 test1(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
		Matrix4x4 scalres(0, 28, 22, 16, 178, 156, 134, 112, 322, 284, 246, 208, 466, 412, 358, 304);
	}

	// - Obrót X, Y, Z
	{
		Matrix4x4 rotXResult = Matrix4x4(0, 1, 2, 3, -8, -9, -10, -11, 4, 5, 6, 7, 12, 13, 14, 15);
		Matrix4x4 rotYResult = Matrix4x4(8, 9, 10, 11, 4, 5, 6, 7, 0, -1, -2, -3, 12, 13, 14, 15);
		Matrix4x4 rotZResult = Matrix4x4(-4, -5, -6, -7, 0, 1, 2, 3, 8, 9, 10, 11, 12, 13, 14, 15);

		Matrix4x4 rotX = Matrix4x4();
		Matrix4x4 rotY = Matrix4x4();
		Matrix4x4 rotZ = Matrix4x4();
		Matrix4x4 temp = Matrix4x4();

		rotX.rotateX(90);
		rotY.rotateY(90);
		rotZ.rotateZ(90);

		std::cout << rotX.multiply(test1).toString() << '\n';
		std::cout << rotY.multiply(test1).toString() << '\n';
		std::cout << rotZ.multiply(test1).toString() << '\n';
	}


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
		Matrix4x4 mulres(34, 28, 22, 16, 178, 156, 134, 112, 322, 284, 246, 208, 466, 412, 358, 304); // old mulres
		Matrix4x4 test3(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15); // cpy of old test1

		// It wont be equal as we multiply b * a not a * b as before.

		if (test2.multiply(test3) == mulres)
			std::cout << "Multiplication works :( !" << std::endl;
		else
			std::cout << "Multiplication doesn't work :)" << std::endl;
	}
	

	return 0;
}