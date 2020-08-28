#pragma once
#include <iostream>
#include "SimpleFraction.hpp"

class EquationNode {
public:
    explicit EquationNode(std::string);

    SimpleFraction computeValue();

    [[nodiscard]] bool isValue() const;
    [[nodiscard]] bool isOperator() const;

    [[nodiscard]] EquationNode *getParent();
    void setParent(EquationNode *);

    [[nodiscard]] std::string getOperator();

    void setLeftToken(EquationNode *);
    void setRightToken(EquationNode *);

    EquationNode *getLeftToken();
    EquationNode *getRightToken();

    [[maybe_unused]] std::string getValue();
    [[maybe_unused]] void nodeInfo();
private:
    std::string value_;
    std::string operator_;
    EquationNode *parent_token_;
    EquationNode *left_token_;
    EquationNode *right_token_;
};