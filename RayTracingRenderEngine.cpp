#include "RayTracingRenderEngine.hpp"
#include <iostream>

#include "Line.hpp"

RayTracingRenderEngine::RayTracingRenderEngine()
{
	for (std::array<char, 60>& column : pixels)
	{
		for (char& pixel : column)
		{
			pixel = 46;
		}
	}
}

void RayTracingRenderEngine::Draw(const HANDLE& outputHandle) {
	WriteConsoleA(outputHandle, pixels.data(), pixels.size() * pixels.data()[0].size(), nullptr, nullptr);
}

void RayTracingRenderEngine::RayCast(Vector cameraPosition, Vector cameraDirection)
{
	float pixelSize = 1.0 / 60.0;
	float screenDistance = 1.f;

	Vector screenPosition = cameraPosition + cameraDirection * screenDistance;

	Vector worldUp(0.0, 1.0, 0.0);

	Vector check(0.0, 1.0, 0.0);

	if (cameraDirection.isClose(check, 0.1))
	{
		worldUp = Vector(0.0, 0.0, 1.0);
	}

	Vector diff = screenPosition - cameraPosition;
	diff *= -1;
	Vector screenLeft = diff.cross(worldUp).normalize();

	Vector screenDown = screenPosition.cross(screenLeft).normalize();

	for (int i = 0; i < 60; ++i)
	{
		for (int j = 0; j < 60; ++j)
		{
			Vector pixelLocation = screenPosition + (screenLeft * ((j - 30) * pixelSize));
			pixelLocation = pixelLocation + (screenDown * ((i - 30) * pixelSize));

			Line line = Line::FromTwoPoints(cameraPosition, pixelLocation);
			pixels[i][j] = Line::isRayCastIntersecting(line);
			pixels[i][j] <<= 1;
			pixels[i][j] += 46;
		}
	}
}
