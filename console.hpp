#pragma once
#include <windows.h>
#undef min;
#undef max;

namespace Console {

	const auto invalidHandle = INVALID_HANDLE_VALUE;

	auto GetInputHandle() {
		return HANDLE { GetStdHandle(STD_INPUT_HANDLE) };
	}

	auto GetOutputHandle() {
		return HANDLE { GetStdHandle(STD_OUTPUT_HANDLE) };
	}

}

