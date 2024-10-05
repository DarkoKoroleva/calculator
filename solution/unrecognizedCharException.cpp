#include "../header/unrecognizedCharException.h"

UnrecognizedCharException::UnrecognizedCharException(std::string message, char c) : message{ message }, c{ c } {}

std::string UnrecognizedCharException::getMessage() const {
    return message + " " + c;
}
