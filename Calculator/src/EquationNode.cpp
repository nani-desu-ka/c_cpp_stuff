#include "EquationNode.hpp"
#include "help_functions.hpp"

EquationNode::EquationNode(std::string token) {
    left_token_ = nullptr;
    right_token_ = nullptr;
    value_ = "";
    operator_ = "_";
    switch (token[0]) {
        case '+':
            [[fallthrough]];
        case '-':
            [[fallthrough]];
        case '*':
            [[fallthrough]];
        case '/':
            [[fallthrough]];
        case '^':
            operator_ = token[0];
            break;
        default:
            value_ = token;
            break;
    }
}

SimpleFraction EquationNode::computeValue() {
    if (operator_ == "_") {
        return decimalToFraction(CustomFloat(value_));
    }
    switch (operator_[0]) {
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