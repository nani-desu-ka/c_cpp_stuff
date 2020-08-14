#include "EquationNode.hpp"
#include "help_functions.hpp"

EquationNode::EquationNode() {
    left_token_ = nullptr;
    right_token_ = nullptr;
    value_ = "";
    operator_ = "_";
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