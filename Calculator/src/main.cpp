#include <iostream>
#include "help_functions.hpp"
#include "CustomFloat.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokenized_eq = equationTokenizer(input);
    for (auto &token : tokenized_eq) {
        std::cout << token << '\n';
    }
    return 0;
}
