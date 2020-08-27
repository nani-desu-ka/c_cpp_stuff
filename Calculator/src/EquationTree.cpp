#include "EquationTree.hpp"
#include "EquationNode.hpp"

EquationTree::EquationTree(const std::vector<std::string> &token_list) {
    head_ = nullptr;
    for (auto &token : token_list) {
        node_list_.emplace_back(token);
    }
    for (int i = 0; i < node_list_.size(); i++) {
        if (node_list_[i].isOperator()) {
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
    }

    while (!first_priority_.empty()) {
        int index = first_priority_.front();

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

        first_priority_.pop();
    }

    while (!second_priority_.empty()) {
        int index = second_priority_.front();

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
        second_priority_.pop();
    }

    while (!third_priority_.empty()) {
        int index = third_priority_.front();

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
        third_priority_.pop();
    }
    for (auto &node : node_list_) {
        if (node.getParent() == nullptr) head_ = &node;
    }
}

SimpleFraction EquationTree::computeEquation() {
    return head_->computeValue();
}