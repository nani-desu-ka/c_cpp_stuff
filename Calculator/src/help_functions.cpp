#include "help_functions.hpp"
#include <string>

SimpleFraction decimalToFraction(CustomFloat value) {
    float temp_value = value.getValue();
    std::string str_value = std::to_string(temp_value);
    int lower = 1;
    for (int i = 0; i < value.getPrecision(); i++) {
        temp_value *= 10;
        lower *= 10;
    }

    SimpleFraction temp_fraction = SimpleFraction(static_cast<int>(temp_value), lower);
    temp_fraction.relax();
    return temp_fraction;
}