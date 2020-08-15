#include "EquationTree.hpp"

EquationTree::EquationTree(std::vector<std::string> token_list) {
    // Здесь должно быть реализовано построение дерева из листа
}

SimpleFraction EquationTree::computeEquation() {
    return head_->computeValue();
}