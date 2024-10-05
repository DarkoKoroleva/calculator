#include "../header/funcSin.h"

double FuncSin::execute(const std::vector<double>& args) const
{
	if (args.size() == 1) {
		return sin(args[0]);
	}
	else {
		throw InvalidArgsException("command Sin takes 1 argument");
	}
}
