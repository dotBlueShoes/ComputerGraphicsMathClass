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

#include "console.hpp"

bool loop = true;
float yaw = 0.0;
float pitch = 0.0;
float radius = 5.0;

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


void KeyEvent(KEY_EVENT_RECORD keyEvent) {
	//printf("Key event: ");

	const auto keyZ = 0x5A;
	const auto keyX = 0x58;
	const auto keyC = 0x43;
	const auto keyV = 0x56;
	const auto keyB = 0x42;
	const auto keyN = 0x4E;
	const float step = 0.1f;

	switch (keyEvent.wVirtualKeyCode) {
		case keyZ: {
			yaw += 10;
			break;
		}
		case keyX: {
			yaw -= 10;
			break;
		}
		case keyC: {
			pitch += 10;
			break;
		}
		case keyV: {
			pitch -= 10;
			break;
		}
		case keyB: {
			radius += 0.5;
			break;
		}
		case keyN: {
			radius -= 0.5;
			break;
		}
	}

	//if (keyEvent.bKeyDown)
	//	loop = false;
	//printf("key pressed\n");
	//else printf("key released\n");
}


int main() {
	RayTracingRenderEngine renderer;
	using std::string;
	string output("");

	// Input
	std::array<INPUT_RECORD, 128> inputBuffer;
	DWORD inputRead, index;
	DWORD numberOfEvents;

	auto outputHandle = Console::GetOutputHandle();
	if (outputHandle == Console::invalidHandle) {
		output += "inputProcess == INVALID_HANDLE_VALUE!";
		std::cout << output << std::endl;
		return 0;
	}

	auto inputHandle = Console::GetInputHandle();
	if (inputHandle == Console::invalidHandle) {
		output += "inputProcess == INVALID_HANDLE_VALUE!";
		std::cout << output << std::endl;
		return 0;
	}

	while (loop) {

		if (!PeekConsoleInput(
			inputHandle,
			inputBuffer.data(),
			inputBuffer.size(),
			&inputRead
		)) {
			output += "ReadConsoleInput == ERROR!";
			std::cout << output << std::endl;
			return 0;
		}

		for (index = 0; index < inputRead; index++) {
			switch (inputBuffer[index].EventType) {
				case KEY_EVENT: // keyboard input
					KeyEvent(inputBuffer[index].Event.KeyEvent);
					break;
				case MOUSE_EVENT:				// mouse input
				case WINDOW_BUFFER_SIZE_EVENT:	// scrn buf. resizing
				case FOCUS_EVENT:				// disregard focus events
				case MENU_EVENT:				// disregard menu events
					break;
				default:
					break;
			}
		}

		FlushConsoleInputBuffer(inputHandle);

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

		Vector cameraDirection = (cameraPosition * -1).normalize();

		renderer.RayCast(cameraPosition, cameraDirection);
		renderer.Draw(outputHandle);
	}
	

	std::cout << output << std::endl;
	return 0;
}