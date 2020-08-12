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

[[nodiscard]] int CustomFloat::getPrecision() const {
    return precision_;
}

[[maybe_unused]] [[nodiscard]] int CustomFloat::getIntPart() const {
    return int_part_;
}

[[nodiscard]] float CustomFloat::getValue() const {
    return value_;
}