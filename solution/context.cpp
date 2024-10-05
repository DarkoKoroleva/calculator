#include "../header/context.h"

void Context::setStrategy(Strategy* newStrategy) {
	strategy = newStrategy;
}

double Context::executeStrategy(const std::vector<double>& args){
	return strategy->execute(args);
}
