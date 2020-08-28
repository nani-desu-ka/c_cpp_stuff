#include "help_functions.hpp"
#include <string>

SimpleFraction decimalToFraction(CustomFloat value) {
    float temp_value = value.getValue();
    std::string str_value = std::to_string(temp_value);
    int lower = 1;
    for (int i = 0; i < value.getPrecision(); i++) {
        temp_value *= 10;
        lower *= 10;
    }

    SimpleFraction temp_fraction = SimpleFraction(static_cast<int>(temp_value), lower);
    temp_fraction.relax();
    return temp_fraction;
}

std::vector<std::string> equationTokenizer(const std::string &equation) {
    std::vector<std::string> tokenized_eq;
    std::string temp_string;
    for (auto token : equation) {
        if (token == ' ') {
            continue;
        }
        if (token == '(' || token == ')' || token == '+' || token == '-' || token == '/'
        || token == '*' || token == '^') {
            if (!temp_string.empty()) {
                tokenized_eq.push_back(temp_string);
                temp_string.clear();
            }
            temp_string += token;
            tokenized_eq.push_back(temp_string);
            temp_string.clear();
            continue;
        }
        temp_string += token;
    }
    if (!temp_string.empty()) {
        tokenized_eq.push_back(temp_string);
    }
    return tokenized_eq;
}

void equationSimplifier(std::vector<std::string> &equation) {
    std::vector<std::string> simplified_equation;
    if (equation[0] == "-") {
        simplified_equation.emplace_back("0");
    }
    for (int i = 0; i < equation.size(); i++) {
        if (i - 1 > -1 && equation[i - 1] == "(") {
            simplified_equation.emplace_back("0");
        }
        simplified_equation.push_back(equation[i]);
    }
    equation = simplified_equation;
}