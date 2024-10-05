#pragma once
#include "strategy.h"
#include "invalidArgsException.h"
#include <vector>

class Division : public Strategy
{
public:
	double execute(const std::vector<double>& args) const override;
};

