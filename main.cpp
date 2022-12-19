#include <iostream>
#include <fstream>
#include <cmath>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Line.hpp"


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

		Line line1({ 3, 1, 5 }, { -2, 4, 0 });
		Line line2({ 1, -5, 3 }, { -2, 4, 0 });

		if (line1.lineIntersectionCheck(line2))
		{
			Vector point = line1.getLineIntersectionPoint(line2);
			output += "1. ";
			output += point.toString();
			output += '\n';
		}


		{ // 2. Znajdź kąt między prostymi z zdania {1}.
			float angle = line1.getAngleBetweenLines(line2);
			output += "2. ";
			output += std::to_string(angle);
			output += '\n';
		}

	}

	{ // 3. Znajdź punkt przecięcia pomiędzy prostymi:
		Line line1({ 3, -1, 2 }, { -2, 2, -1 });
		Line line2({ 2, 3, 3 }, { -2, 2, 2 });

		Vector point = line1.getLineAndPlaneIntersectionPoint(line2);
		output += "3. ";
		output += point.toString();
		output += '\n';

		{ // 4. Znajdź kąt pomiędzy prostą a płaszczyzną z zadania {2}.
			float angle = line1.getAngleBetweenLineAndPlane(line2);
			output += "4. ";
			output += std::to_string(angle);
			output += '\n';
		}
	}

	{ // 5. Znajdź prostą przecięcia płaszczyzn.
		//Line line1({ 2, -1, 1 }, { 4, 1, 1 });
		//Line line2({ 4, 3, 1 }, { -4, 1, -1 });

		Line line1({ 1, 0, 5 }, { 1, 6, -2 });
		Line line2({ 3, -2, 2 }, { 2, 1, 0 });

		Line line = line1.getPlaneIntersection(line2);
		output += "5. ";
		output += line.getDirectional().toString() + ", " + line.getPoint().toString();
		output += '\n';

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