#include <iostream>
#include <fstream>
#include <cmath>
#include <corecrt_math_defines.h>

#include "Framework.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include "Line.hpp"
#include "RayTracingRenderEngine.hpp"
#include "Segment.hpp"
#include "Sphere.hpp"


Line CreateLineFromTwoPoints(const Vector& point1, const Vector& point2) {
	Vector temp = point2 - point1;
	return { temp, point1 };
}


float clamp(float x, float mi, float ma)
{
	if (x < mi)
		x = mi;
	else if (x > ma)
		x = ma;

	return x;
}


int main() {
	RayTracingRenderEngine renderer;
	using std::string;
	string output("");

	float yaw = 0.;
	float pitch = 0.;
	float radius = 5.;

	bool loop = true;

	while (loop)
	{
		// TO DO
		// Add input reading here

		yaw = clamp(yaw, -90.0, 90.0);

		if (pitch >= 360.0)
		{
			pitch -= 360.0;
		}
		else if (pitch < 0.0)
		{
			pitch += 360.0;
		}

		Vector cameraPosition(0.f, 0.f, 0.f);

		float pitchRadians = pitch * M_PI / 180.f;
		float yawRadians = yaw * M_PI / 180.f;
		cameraPosition.x = radius * std::cos(pitchRadians) * std::cos(yawRadians);
		cameraPosition.y = radius * std::sin(pitchRadians) * std::cos(yawRadians);
		cameraPosition.z = radius * std::sin(yawRadians);

		Vector norm = cameraPosition;
		norm.normalize();

		Vector cameraDirection = norm * -1;

		renderer.RayCast(cameraPosition, cameraDirection);
		renderer.Draw();
	}
	

	std::cout << output << std::endl;
	return 0;
}