#include <iostream>
#include "help_functions.hpp"
#include "CustomFloat.hpp"
#include "EquationTree.hpp"

int main(int argc, char **argv) {
    std::string input;
    if (argc == 1) {
        std::getline(std::cin, input);
    } else {
        for (int i = 1; i < argc; i++) {
            input += argv[i];
        }
    }
    std::vector<std::string> tokenized_eq = equationTokenizer(input);
    equationSimplifier(tokenized_eq);
    EquationTree test_tree(tokenized_eq);
    std::cout << test_tree.computeEquation() << '\n';
    return 0;
}
