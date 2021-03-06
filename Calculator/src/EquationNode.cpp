#include "EquationNode.hpp"
#include "help_functions.hpp"

EquationNode::EquationNode(std::string token) {
    parent_token_ = nullptr;
    left_token_ = nullptr;
    right_token_ = nullptr;
    value_ = "";
    operator_ = "_";
    switch (token[0]) {
        case '(':
            [[fallthrough]];
        case ')':
            [[fallthrough]];
        case '+':
            [[fallthrough]];
        case '-':
            [[fallthrough]];
        case '*':
            [[fallthrough]];
        case '/':
            [[fallthrough]];
        case '^':
            operator_ = token;
            break;
        default:
            value_ = token;
            break;
    }
}

SimpleFraction EquationNode::computeValue() {
    switch (operator_[0]) {
        case '_': return decimalToFraction(CustomFloat(value_));
        case '+': return left_token_->computeValue() + right_token_->computeValue();
        case '-': return left_token_->computeValue() - right_token_->computeValue();
        case '*': return left_token_->computeValue() * right_token_->computeValue();
        case '/': return left_token_->computeValue() / right_token_->computeValue();
        case '^': return left_token_->computeValue() ^ right_token_->computeValue();
        default: return decimalToFraction(CustomFloat("0"));
    }
}

void EquationNode::setLeftToken(EquationNode *token) {
    left_token_ = token;
}

void EquationNode::setRightToken(EquationNode *token) {
    right_token_ = token;
}

[[nodiscard]] bool EquationNode::isValue() const {
    if (value_.empty()) return false;
    else return true;
}

[[maybe_unused]] [[nodiscard]] bool EquationNode::isOperator() const {
    if (operator_ == "_") return false;
    return true;
}

[[nodiscard]] std::string EquationNode::getOperator() {
    return operator_;
}

[[nodiscard]] EquationNode *EquationNode::getParent() {
    return parent_token_;
}

void EquationNode::setParent(EquationNode *node) {
    parent_token_ = node;
}

[[maybe_unused]] std::string EquationNode::getValue() {
    return value_;
}

EquationNode *EquationNode::getLeftToken() {
    return left_token_;
}

EquationNode *EquationNode::getRightToken() {
    return right_token_;
}

[[maybe_unused]] void EquationNode::nodeInfo() {
    if (getOperator() != "(" && getOperator() != ")") {
        std::cout << "Node: " << getValue() << getOperator() << '\n';
        if (getParent() != nullptr) std::cout << "Parent: " << getParent()->getValue() << getParent()->getOperator() << '\n';
        else std::cout << "Head" << '\n';
        if (getLeftToken() != nullptr) std::cout << "LeftToken: " << getLeftToken()->getValue() << getLeftToken()->getOperator() << '\n';
        if (getRightToken() != nullptr) std::cout << "RightToken: " << getRightToken()->getValue() << getRightToken()->getOperator()
                                                       << '\n';
        std::cout << '\n';
    }
}