#include "CustomFloat.hpp"

CustomFloat::CustomFloat(std::string value) {
    int i = 0;
    while (value[i] != '.' && i < value.length()) {
        i++;
    }
    int j = 0;
    while (i + j < value.length()) {
        j++;
    }
    if (j != 0) {
        j--;
    }
    value_ = stof(value);
    precision_ = j;
    int_part_ = i;
}

int CustomFloat::getPrecision() {
    return precision_;
}

int CustomFloat::getIntPart() {
    return int_part_;
}

float CustomFloat::getValue() {
    return value_;
}