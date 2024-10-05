#include "../header/multiply.h"

double Multiply::execute(const std::vector<double>& args) const {
	if (args.size() == 2) {
		return args[0]*args[1];
	}
	else {
		throw InvalidArgsException("command Multiply takes 2 arguments");
	}
}
