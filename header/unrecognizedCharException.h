#pragma once
#include <string>

class UnrecognizedCharException : public std::exception {
public:
    UnrecognizedCharException(std::string message, char c);
    std::string getMessage() const;
private:
    std::string message;
    char c;
};

