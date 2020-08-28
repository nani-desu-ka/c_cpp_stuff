#include "EquationTree.hpp"
#include "EquationNode.hpp"

EquationTree::EquationTree(const std::vector<std::string> &token_list) {
    head_ = nullptr;
    brackets_amount_ = 0;
    for (auto &token : token_list) {
        node_list_.emplace_back(token);
    }
    int first_index = -1;
    for (int i = 0; i < node_list_.size(); i++) {
        if (node_list_[i].getOperator() == "(") {
            if (brackets_amount_ == 0) {
                first_index = i;
            }
            brackets_amount_++;
        }
        if (node_list_[i].getOperator() == ")") {
            brackets_amount_--;
            if (brackets_amount_ == 0) {
                initHelper(first_index, i);
                first_index = -1;
            }
        }
    }
    if (brackets_amount_ != 0) {
        std::cerr << "INCORRECT BRACKET STRUCTURE" << '\n';
        exit(EXIT_FAILURE);
    }
    for (auto &node : node_list_) {
        if (node.getParent() == nullptr && node.getOperator() != "(" && node.getOperator() != ")") head_ = &node;
    }
}

SimpleFraction EquationTree::computeEquation() {
    return head_->computeValue();
}

void EquationTree::initHelper(int first, int last) {
    int first_index = -1;
    for (int i = first + 1; i < last; i++) {
        if (node_list_[i].getOperator() == "(") {
            if (brackets_amount_ == 0) {
                first_index = i;
            }
            brackets_amount_++;
        }
        if (node_list_[i].getOperator() == ")") {
            brackets_amount_--;
            if (brackets_amount_ == 0) {
                initHelper(first_index, i);
                first_index = -1;
            }
        }
    }
    if (brackets_amount_ != 0) {
        std::cerr << "INCORRECT BRACKET STRUCTURE" << '\n';
        exit(EXIT_FAILURE);
    }
    for (int i = first + 1; i < last; i++) {
        if (node_list_[i].isOperator()) {
            if (node_list_[i].getOperator() == "(") brackets_amount_++;
            if (brackets_amount_ == 0) {
                switch (node_list_[i].getOperator()[0]) {
                    case '^':
                        first_priority_.push(i);
                        continue;
                    case '*':
                        [[fallthrough]];
                    case '/':
                        second_priority_.push(i);
                        continue;
                    case '+':
                        [[fallthrough]];
                    case '-':
                        third_priority_.push(i);
                        continue;
                    default:
                        std::cerr << "UNEXPECTED OPERATOR" << '\n';
                        exit(EXIT_FAILURE);
                }
            }
            if (node_list_[i].getOperator() == ")") brackets_amount_--;
        }
    }

    while (!first_priority_.empty()) {
        operatorProcessor(first_priority_.front());
        first_priority_.pop();
    }

    while (!second_priority_.empty()) {
        operatorProcessor(second_priority_.front());
        second_priority_.pop();
    }

    while (!third_priority_.empty()) {
        operatorProcessor(third_priority_.front());
        third_priority_.pop();
    }
}

void EquationTree::operatorProcessor(int index) {
    int i = 0;
    while (!node_list_[index + i].isValue()) {
        i++;
    }
    EquationNode *temp_node = &node_list_[index + i];
    while (temp_node->getParent() != nullptr) {
        temp_node = temp_node->getParent();
    }
    temp_node->setParent(&node_list_[index]);
    node_list_[index].setRightToken(temp_node);

    i = 0;
    while (!node_list_[index - i].isValue()) {
        i++;
    }
    temp_node = &node_list_[index - i];
    while (temp_node->getParent() != nullptr) {
        temp_node = temp_node->getParent();
    }
    temp_node->setParent(&node_list_[index]);
    node_list_[index].setLeftToken(temp_node);
}