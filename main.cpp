#include <iostream>
#include <fstream>
#include <cmath>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Line.hpp"
#include "Segment.hpp"
#include "Sphere.hpp"


Line CreateLineFromTwoPoints(const Vector& point1, const Vector& point2) {
	Vector temp = point2 - point1;
	return { temp, point1 };
}


int main() {

	using std::string;
	string output("");
	
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
			float angle = line1.getAngleBetweenLines(line2) * 180 / Constants::pi<float>;
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
			float angle = line1.getAngleBetweenLineAndPlane(line2) * 180 / Constants::pi<float>;
			output += "4. ";
			output += std::to_string(angle);
			output += '\n';
		}
	}

	{ // 5. Znajdź prostą przecięcia płaszczyzn.
		Line plane1({ 2, -1, 1 }, { 4, 1, 1 });
		Line plane2({ 4, 3, 1 }, { -4, 1, -1 });

		//Line plane1({ 1, 0, 5 }, { 1, 6, -2 });
		//Line plane2({ 3, -2, 2 }, { 2, 1, 0 });

		//Line plane1({ 7, 5.5, 2 }, { 1.2, 4, -1.8 });
		//Line plane2({ 3.4, 3, 5 }, { 2, 1, 1 });

		Line result = plane1.getPlaneIntersection(plane2);
		output += "5. Directional ";
		output += result.getDirectional().toString();
		output += ", Point ";
		output += result.getPoint().toString();
		output += '\n';

		{ // 6. Znajdź kąt pomiędzy płaszczyznami z zadania {5}.
			float angle = plane1.getAngleBetweenLines(plane2) * 180 / Constants::pi<float>;
			output += "6. ";
			output += std::to_string(angle);
			output += '\n';
		}
	}

	{ // 7. Znajdź punkt przecięcia dwóch odcinków opisanych punktami:
		// A { 5, 5, 4 }, A' { 10, 10, 6 }
		// B { 5, 5, 5 }, B' { 10, 10, 3 } 
		Segment segmentA({ 5, 5, 4 }, { 10, 10, 6 });
		Segment segmentB({ 5, 5, 5 }, { 10, 10, 3 });

		if (segmentA.lineBetween.lineIntersectionCheck(segmentB.lineBetween)) {
			Vector point = segmentA.lineBetween.getLineIntersectionPoint(segmentB.lineBetween);
			output += "7. ";
			output += point.toString();
			output += '\n';
		}

	}

	{ // 1. AKA 8. Znajdź punkt przecięcia sfery o początku w centrum układu współrzędnych [0, 0, 0] i 
	  //  promieniu sqrt(26)., oraz prostej przechodzącej przez punkty.

		Sphere sphere({ 0,0,0 }, std::sqrt(26));
		//Sphere sphere({ 0,0,0 }, 3);
		//Segment segment({ 3, -1, -2 }, { 5, 3, -4 });
		//Line line({ 3, -1, -2 }, { 5, 3, -4 });
		//Line line = Line::FromTwoPoints({ 3, -1, -2 }, { 5, 3, -4 });
		Vector A { 3, -1, -2 };
		Vector B { 5, 3, -4 };
		Line lineBetween = CreateLineFromTwoPoints(A, B);

		Sphere::IntersectionResult result = sphere.getIntersection(lineBetween);
		output += "8. ";
		output += result.data()[0].toString();
		output += result.data()[1].toString();
		output += '\n';

	}
	

	std::cout << output << std::endl;
	return 0;
}