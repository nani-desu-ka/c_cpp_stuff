#include <iostream>
#include "SimpleFraction.hpp"
#include "help_functions.hpp"
#include "CustomFloat.hpp"

int main() {
//    CustomFloat test = CustomFloat("433.234");
//    std::cout << test.getIntPart() << ' ' << test.getPrecision() << ' ' << test.getValue() << '\n';
    SimpleFraction test_frac = decimalToFraction(CustomFloat("433.5"));
    std::cout << test_frac << std::endl;
    return 0;
}
