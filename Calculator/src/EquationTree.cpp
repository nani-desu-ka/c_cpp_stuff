#include "EquationTree.hpp"

EquationTree::EquationTree(std::vector<std::string> token_list) {
    // ����� ������ ���� ॠ�������� ����஥��� ��ॢ� �� ����
}

SimpleFraction EquationTree::computeEquation() {
    return head_->computeValue();
}