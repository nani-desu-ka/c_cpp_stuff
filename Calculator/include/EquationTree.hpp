#pragma once
#include "EquationNode.hpp"
#include <vector>
#include "SimpleFraction.hpp"

class EquationTree {
public:
    EquationTree(std::vector<std::string>);
    SimpleFraction computeEquation();
private:
    EquationNode *head_;
    std::vector<EquationNode *> nodes_;
};