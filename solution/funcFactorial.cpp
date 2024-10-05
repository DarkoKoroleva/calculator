#include "../header/funcFactorial.h"

double FuncFactorial::execute(const std::vector<double>& args) const
{
	if (args.size() == 1) {
		int n = (int) args[0];
		if (n < 0) return 0;
		if (n == 1) return 1;
		double result = 1;
		if (n > 170) {
			throw InvalidArgsException("it's impossible to calculate the factorial of such a large number");
		}
		for (int i = 2; i <= n; i++) {
			result *= i;
		}
		return result;
	}
	else {
		throw InvalidArgsException("command Factorial takes 1 argument");
	}
}
