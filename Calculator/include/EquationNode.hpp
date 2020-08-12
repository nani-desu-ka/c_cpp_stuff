#pragma once
#include <iostream>
#include "SimpleFraction.hpp"

class EquationNode {
public:
    EquationNode();
    SimpleFraction computeValue();
private:
    std::string value_;
    char operator_;
    EquationNode *left_token_;
    EquationNode *right_token_;
};