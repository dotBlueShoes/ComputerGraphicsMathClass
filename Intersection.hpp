#pragma once
#include "Straight.hpp"

class Intersection {
	Straight first, other;
public:
	Intersection(const Straight& newFirst, const Straight& newOther) : first(newFirst), other(newOther) {};
};