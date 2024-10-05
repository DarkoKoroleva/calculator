#include "../header/division.h"

double Division::execute(const std::vector<double>& args) const
{
    if (args.size() == 2) {
        if (args[1] == 0) throw InvalidArgsException("you shouldn't divide by 0");
        return args[0] / args[1];
    }
    else {
        throw InvalidArgsException("command Division takes 2 argument");
    }
}
