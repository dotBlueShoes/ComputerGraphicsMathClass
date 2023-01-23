#include "RayTracingRenderEngine.hpp"
#include <iostream>

#include "Line.hpp"

RayTracingRenderEngine::RayTracingRenderEngine()
{
	for (std::array<bool, 60>& column : pixels)
	{
		for (bool& pixel : column)
		{
			pixel = false;
		}
	}
}

void RayTracingRenderEngine::Draw()
{
	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			if (pixels[i][j])
			{
				std::cout << "0";
			}
			else
			{
				std::cout << ".";
			}
		}
		std::cout << std::endl;
	}
}

void RayTracingRenderEngine::RayCast(Vector cameraPosition, Vector cameraDirection)
{
	float pixelSize = 1.0 / 60.0;
	float screenDistance = 1.f;

	Vector screenPosition = cameraPosition + cameraDirection + screenDistance;

	Vector worldUp(0.0, 0.0, 1.0);

	Vector check(0.0, 1.0, 0.0);

	if (cameraDirection.isClose(check, 0.1))
	{
		worldUp = Vector(0.0, 0.0, 1.0);
	}

	Vector diff = screenPosition - cameraPosition;
	diff.cross(worldUp).normalize();
	Vector screenLeft = diff * -1;

	Vector screenDown = screenPosition.cross(screenLeft);
	screenDown.normalize();

	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			Vector pixelLocation = screenPosition + screenLeft * ((j - 30) * pixelSize);
			pixelLocation = pixelLocation + screenDown * ((i - 30) * pixelSize);

			Line line = Line(cameraPosition, pixelLocation);
			pixels[i][j] = Line::isRayCastIntersecting(line);
		}
	}
}
