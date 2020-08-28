#pragma once
#include "EquationNode.hpp"
#include <vector>
#include "SimpleFraction.hpp"
#include <queue>

class EquationTree {
public:
    explicit EquationTree(const std::vector<std::string>&);
    void initHelper(int , int);
    void operatorProcessor(int);
    SimpleFraction computeEquation();
private:
    std::queue<int> first_priority_;
    std::queue<int> second_priority_;
    std::queue<int> third_priority_;
    int brackets_amount_;
    EquationNode *head_;
    std::vector<EquationNode> node_list_;
};