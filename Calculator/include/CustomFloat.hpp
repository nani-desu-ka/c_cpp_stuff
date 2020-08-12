#pragma once
#include <string>

class CustomFloat {
public:
    explicit CustomFloat(std::string);
    [[nodiscard]] float getValue() const;
    [[nodiscard]] int getPrecision() const;
    [[maybe_unused]] [[nodiscard]] int getIntPart() const;
private:
    float value_;
    int precision_;
    [[maybe_unused]] int int_part_;
};