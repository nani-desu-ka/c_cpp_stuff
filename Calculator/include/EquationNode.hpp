#pragma once
#include <iostream>
#include "SimpleFraction.hpp"

class EquationNode {
public:
    EquationNode(std::string);
    SimpleFraction computeValue();
    void setLeftToken(EquationNode *);
    void setRightToken(EquationNode *);
private:
    std::string value_;
    std::string operator_;
    EquationNode *left_token_;
    EquationNode *right_token_;
};