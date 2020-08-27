#include <iostream>
#include "help_functions.hpp"
#include "CustomFloat.hpp"
#include "EquationTree.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokenized_eq = equationTokenizer(input);
    EquationTree test_tree(tokenized_eq);
    std::cout << test_tree.computeEquation() << '\n';
    return 0;
}
