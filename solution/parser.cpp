#include "../header/parser.h"

bool comp(string oper1, string oper2) { //comparator
	return OPER.at(oper1) >= OPER.at(oper2);
}

vector<cv> parse(string s) {
	string brackets = "()";
	string binOperators = "+-*^/";
	string unaOperators = "sin, cos, ln, !";
	string numbers = "0123456789.-";

	vector<cv> parsed;

	for (size_t i = 0; i < s.length(); i++) {
		if (numbers.find(s[i]) != string::npos) {
			if (s[i] == '-') {
				if (i == 0) {
					parsed.push_back(cv(NUM, s[i]));
				}
				else if (parsed[i - 1].first != NUM) {
					parsed.push_back(cv(NUM, s[i]));
				}
				else {
					parsed.push_back(cv(BIN_OPR, s[i]));
				}
				continue;
			} 
			parsed.push_back(cv(NUM, s[i]));
		}
		else if (binOperators.find(s[i]) != string::npos) {
			parsed.push_back(cv(BIN_OPR, s[i]));
		}
		else if (unaOperators.find(s[i]) != string::npos) {
			parsed.push_back(cv(UNA_OPR, s[i]));
		}
		else if (brackets.find(s[i]) != string::npos) {
			parsed.push_back(cv(BRC, s[i]));
		}
		else {
			throw UnrecognizedCharException("unrecognized char", s[i]);
		}
	}
	return parsed;
}


double evaluate(vector<cv> parsed) {
	vector<double> values;
	vector<ts> operators;

	int countBrc = 0;
	string s; //get numbers&operators
	type typeFlag = ((parsed[0].first == UNA_OPR || parsed[0].first == BIN_OPR) ? OPR : parsed[0].first);

	for (size_t i = 0; i < parsed.size(); i++) {
		if (parsed[i].first == NUM) {
			if (!s.empty() && typeFlag == OPR) {
				operators.push_back(ts(parsed[i-1].first, s));
				s.clear();
			}
			s += parsed[i].second;
			typeFlag = NUM;
		}
		else if (parsed[i].first == UNA_OPR || parsed[i].first == BIN_OPR) {
			if (!s.empty()) {
				if (typeFlag == NUM) {
					values.push_back(stod(s));
					s.clear();
				}
				else if (parsed[i].first != parsed[i - 1].first) {
					operators.push_back(ts(parsed[i - 1].first, s));
					s.clear();
				}
			}
			s += parsed[i].second;
			typeFlag = OPR;
		}
		else {
			if (!s.empty()) { //the last number
				if (parsed[i - 1].first == NUM) {
					values.push_back(stod(s));
				}
				else if (parsed[i - 1].first == UNA_OPR || parsed[i - 1].first == BIN_OPR) {
					operators.push_back(ts(parsed[i - 1].first, s));
				}
				s.clear();
			}
			if (parsed[i].second == '(') {
				size_t j = i + 1;
				countBrc++;
				for (j; j < parsed.size(); j++) {
					if (parsed[j].second == '(') {
						countBrc++;
					}
					else if (parsed[j].second == ')') {
						countBrc--;
						if (countBrc == 0) break;
					}
				}

				values.push_back(evaluate(vector<cv> (parsed.begin() + i + 1, parsed.begin() + j)));
				i = j;
				
				if (j == parsed.size()) {
					throw InvalidArgsException("missing closed bracket");
				}
			}
		}
	}

	if (!s.empty()) { //the last number
		if (parsed[parsed.size() - 1].first == NUM) values.push_back(stod(s));
		else if (typeFlag == OPR) operators.push_back(ts(parsed[parsed.size() - 1].first, s));
		s.clear();
	}
	

	Context result;
	
	for (size_t i = 0; i < operators.size();) {
		std::vector<double> arg;
		int j = fmin(i + 1, operators.size() - 1);
		if (comp(operators[i].second, operators[j].second)) {
			arg.clear();
			if (operators[i].second == "+") {
				result.setStrategy(new Add());
			}
			else if (operators[i].second == "-") {
				result.setStrategy(new Subtract());
			} 
			else if (operators[i].second == "*") {
				result.setStrategy(new Multiply());
			} 
			else if (operators[i].second == "^") {
				result.setStrategy(new Elevate());
			} 
			else if (operators[i].second == "/") {
				result.setStrategy(new Division());
			}
			else if (operators[i].second == "sin") {
				result.setStrategy(new FuncSin());
			}
			else if (operators[i].second == "!") {
				result.setStrategy(new FuncFactorial());
			}
			else if (operators[i].second == "ln") {
				result.setStrategy(new FuncLn());
			}
			else {
				throw InvalidArgsException("No such operator " + operators[i].second);
			}

			if (operators[i].first == BIN_OPR) {
				arg.push_back(values[i]);
				arg.push_back(values[i + 1]);
				values[i] = result.executeStrategy(arg); //!!
				values.erase(values.begin() + i + 1, values.begin() + i + 2);
				operators.erase(operators.begin() + i);
			} else if (operators[i].first == UNA_OPR) {
				arg.push_back(values[i]);
				values[i] = result.executeStrategy(arg); //!!
				operators.erase(operators.begin() + i);
			}
		
			if (i > 0) i--;
		}
		else {
			i++;
		}
	}

	return values[0];
}
