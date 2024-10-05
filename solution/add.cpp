#include "../header/add.h"


double Add::execute(const std::vector<double>& args) const {
	if (args.size() == 2) {
		return args[0] + args[1];
	}
	else {
		throw InvalidArgsException("command Add takes 2 arguments");
	}
}