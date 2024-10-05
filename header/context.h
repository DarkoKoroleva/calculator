#pragma once
#include "strategy.h"
#include <vector>

class Context {
private:
	Strategy* strategy;

public:
	void setStrategy(Strategy* newStrategy);

	double executeStrategy(const std::vector<double>& args);
};
