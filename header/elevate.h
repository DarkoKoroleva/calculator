#pragma once
#include "strategy.cpp"
#include <math.h>
#include <vector>
#include "invalidArgsException.h"

class Elevate : public Strategy {
public:
	double execute(const std::vector<double>& args) const override;
};
