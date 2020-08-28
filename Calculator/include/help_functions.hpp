#pragma once

#include "SimpleFraction.hpp"
#include "CustomFloat.hpp"
#include <vector>

SimpleFraction decimalToFraction(CustomFloat);
std::vector<std::string> equationTokenizer(const std::string&);
void equationSimplifier(std::vector<std::string> &);