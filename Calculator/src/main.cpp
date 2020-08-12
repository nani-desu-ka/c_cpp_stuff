#include <iostream>
#include "SimpleFraction.hpp"
#include "help_functions.hpp"
#include "CustomFloat.hpp"

int main() {
    std::string input;
    std::getline(std::cin, input);
    std::vector<std::string> tokenized_eq = equationTokenizer(input);
    for (auto &token : tokenized_eq) {
        std::cout << token << '\n';
    }
//    CustomFloat test = CustomFloat("433.234");
//    std::cout << test.getIntPart() << ' ' << test.getPrecision() << ' ' << test.getValue() << '\n';
//    SimpleFraction test_frac = decimalToFraction(CustomFloat("433"));
//    std::cout << test_frac << std::endl;
    return 0;
}
