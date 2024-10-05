#include "../header/parser.h"
using namespace std;

int main() {
	string s = "sin(-3.14/2-1)*3-1+7";
	string const & ss = s;
	try {
		std::cout << evaluate(parse(s)) << endl;
	}
	catch (InvalidArgsException e) {
		std::cout << e.getMessage() << endl;
	}
	return 0;
}