#pragma once
#include "strategy.h"
#include "invalidArgsException.h"
#include <vector>


class FuncSin : public Strategy {
public:
	double execute(const std::vector<double>& args) const override;
};
