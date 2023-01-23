#pragma once
#include <array>

#include <windows.h>
#undef min;
#undef max;

#include "Vector.hpp"

class RayTracingRenderEngine
{
private:
	std::array<std::array<char, 60>, 60> pixels;

public:
	RayTracingRenderEngine();

	void Draw(const HANDLE& outputHandle);
	void RayCast(Vector cameraPosition, Vector cameraDirection);
};

