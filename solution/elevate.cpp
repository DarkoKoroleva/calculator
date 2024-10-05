#include "../header/elevate.h"


double Elevate::execute(const std::vector<double>& args) const {
	if (args.size() == 2) {
		return pow(args[0], args[1]);
	}
	else {
		throw InvalidArgsException("command Elevate takes 2 arguments");
	}
}