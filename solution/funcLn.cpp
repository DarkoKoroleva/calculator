#include "../header/funcLn.h"

double FuncLn::execute(const std::vector<double>& args) const
{
	if (args.size() == 1) {
		if (args[0] <= 0) throw InvalidArgsException("command ln takes a positive argument");
		return log(args[0]);
	}
	else {
		throw InvalidArgsException("command ln takes 1 argument");
	}
}
