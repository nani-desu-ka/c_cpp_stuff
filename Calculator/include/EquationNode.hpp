#pragma once
#include <iostream>
#include "SimpleFraction.hpp"

class EquationNode {
public:
    EquationNode();
    SimpleFraction computeValue();
private:
    std::string value_;
    std::string operator_;
    EquationNode *left_token_;
    EquationNode *right_token_;
};