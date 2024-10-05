#pragma once
#include "parser.h"
#include "../solution/type.cpp"
#include "unrecognizedCharException.h"
#include "invalidArgsException.h"
#include "context.h"
#include"add.h"
#include"subtract.h"
#include"multiply.h"
#include "elevate.h"
#include "division.h"
#include "funcSin.h"
#include "funcFactorial.h"
#include "funcLn.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <string>
#include <map>
using namespace std;
using cv = pair<type, char>; // cv = code-value
using ts = pair<type, string>; // ts = type-string
const map<string, int> OPER = { {"-", 1}, {"+", 1}, {"*", 2}, {"/", 2}, {"^", 3}, {"sin", 4}, {"!", 4}, {"ln", 4}};

bool comp(string oper1, string oper2);

vector<cv> parse(string s);

double evaluate(vector<cv> parsed);


