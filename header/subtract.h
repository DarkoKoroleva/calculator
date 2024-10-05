#pragma once
#include "strategy.cpp"
#include "invalidArgsException.h"
#include <vector>

class Subtract : public Strategy {
	double execute(const std::vector<double>& args) const override;
};
