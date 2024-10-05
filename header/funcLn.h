#pragma once
#include "strategy.h"
#include "invalidArgsException.h"
#include <math.h>

class FuncLn : public Strategy {
public:
	double execute(const std::vector<double>& args) const override;
};
