#pragma once

enum class ErrorCode : int {
	Success = 0,
	Failure = 1
};

#define ErrorType [[nodiscard]] ErrorCode