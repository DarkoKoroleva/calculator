#pragma once
#include "strategy.cpp"
#include "invalidArgsException.h"
#include <vector>

class Multiply : public Strategy {
public:
	double execute(const std::vector<double>& args) const override;
};
