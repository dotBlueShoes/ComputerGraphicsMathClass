#include <iostream>
#include <fstream>
#include <math.h>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"


int main() {

	using std::string;
	string output("");

	// 2. Sprawdź czy operacje działają prawidłowo wyniki zapisz w dokumencie word
	{ // Addition
		Quaternion quaternion1(90, { 1, 0, 0 });
		Quaternion quaternion2(10, { 1, 2, 3 });
		Quaternion result(100, { 2, 2, 3 });
		if ((quaternion1 + quaternion2) == result)
			output += "Poprawnie: Dodawanie\n";
		else 
			output += "Niepoprawnie: Dodawanie\n";
	}

	{ // Subtraction
		Quaternion quaternion1(90, { 1, 0, 0 });
		Quaternion quaternion2(10, { 1, 2, 3 });
		Quaternion result(80, { 0, -2, -3 });
		if ((quaternion1 - quaternion2) == result)
			output += "Poprawnie: Odejmowanie\n";
		else
			output += "Niepoprawnie: Odejmowanie\n";
	}

	{ // Multiplication
		Quaternion quaternion1(90, { 1, 0, 0 });
		Quaternion quaternion2(10, { 1, 2, 3 });
		Quaternion result(899, { 100, 177, 272 });
		if ((quaternion1 * quaternion2) == result)
			output += "Poprawnie: Mnozenie\n";
		else
			output += "Niepoprawnie: Mnozenie\n";
	}

	{ // Division
		Quaternion quaternion1(1, { 3, 3, 3 });
		Quaternion quaternion2(1, { 1, 2, 2 });
		Quaternion temp(1.6, { 0.2, 0.4, -0.2 });
		Quaternion result = quaternion1 / quaternion2;
		output += "Dzielenie:\n";
		output += result.toString() + "\n";
		output += temp.toString() + "\n";
	}

	{ // 3. Punkt[-1, -1, -1] obróć o 270° wokół osi x
		Quaternion quaternion1(270.0f, { -1, -1, -1 });
		Vector axis(1, 0, 0);
		Vector result(-1, -1, 1);
		if (quaternion1.rotateVectorAboutAngleAndAxis(270.0f, axis) == result)
			output += "Poprawnie: Obracanie\n";
		else
			output += "Niepoprawnie: Obracanie\n";
	}

	{ // 4. Udowodnij za pomocą zaimplementowanego przykładu brak przemienności mnożenia  kwaternionów
		Quaternion quaternion1(5, { 1, 2, 3 });
		Quaternion quaternion2(3, { 3, 3, 3 });
		Quaternion result1(-3, { 15, 27, 21 });
		Quaternion result2(-3, { 21, 15, 27 });
		if (quaternion1 * quaternion2 == result1 &&
			quaternion2 * quaternion1 == result2) {
			output += "Przyklad braku przemiennosci: ";
			if (result1 != result2)
				output += " Poprawny";
			else
				output += " Niepoprawny ";
		}
	}

	std::cout << output << std::endl;
	return 0;
}