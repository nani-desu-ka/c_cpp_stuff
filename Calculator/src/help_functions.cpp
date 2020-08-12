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

std::vector<std::string> equationTokenizer(std::string equation) {
    std::vector<std::string> tokenized_eq;
    std::string temp_string;
    for (int i = 0; i < equation.length(); i++) {
        if (equation[i] == ' ') {
            continue;
        }
        if (equation[i] == '(' || equation[i] == ')' || equation[i] == '+' || equation[i] == '-' || equation[i] == '/'
        || equation[i] == '*' || equation[i] == '^') {
            if (!temp_string.empty()) {
                tokenized_eq.push_back(temp_string);
                temp_string.clear();
            }
            temp_string += equation[i];
            tokenized_eq.push_back(temp_string);
            temp_string.clear();
            continue;
        }
        temp_string += equation[i];
    }
    if (!temp_string.empty()) {
        tokenized_eq.push_back(temp_string);
    }
    return tokenized_eq;
}