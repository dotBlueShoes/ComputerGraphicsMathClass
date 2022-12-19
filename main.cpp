#include <iostream>
#include <fstream>
#include <math.h>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Intersection.hpp"


int main() {

	using std::string;
	string output("");

	// y = mx + i
	//  m - nachylenie
	//  i - wyraz wolny
	//  m - deltay/deltax
	// deltax*y = deltay*x + deltax*i
	// deltay*x - deltax*y + deltax*i = 0
	// ax - by + c = 0  :  równanie prostej.

	
	{ // 1.Znajdź punkt przecięcia prostych.

		Straight straight1({ 0, 0, 0 }, { 0, 0, 0 });
		Straight straight2({ 0, 0, 0 }, { 0, 0, 0 });
		Intersection intersection(straight1, straight2);


		{ // 2. Znajdź kąt między prostymi z zdania {1}.

			
		}

	}

	{ // 3. Znajdź punkt przecięcia pomiędzy prostymi:

		{ // 4. Znajdź kąt pomiędzy prostą a płaszczyzną z zadania {2}.

			
		}
	}

	{ // 5. Znajdź prostą przecięcia płaszczyzn.

		{ // 6. Znajdź kąt pomiędzy płaszczyznami z zadania {5}.

			
		}
	}

	{ // 7. Znajdź punkt przecięcia dwóch odcinków opisanych punktami:

	}

	{ // 1. Znajdź punkt przecięcia sfery o początku w centrum układu współrzędnych [0, 0, 0] i 
	  //  promieniu sqrt(26)., oraz prostej przechodzącej przez punkty.

	}
	

	std::cout << output << std::endl;
	return 0;
}