#pragma once
#include <array>

#include "Vector.hpp"

class RayTracingRenderEngine
{
private:
	std::array<std::array<bool, 60>, 60> pixels;

public:
	RayTracingRenderEngine();

	void Draw();
	void RayCast(Vector cameraPosition, Vector cameraDirection);
};

