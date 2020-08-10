#pragma once
#include <string>

class CustomFloat {
public:
    CustomFloat(std::string);
    float getValue();
    int getPrecision();
    int getIntPart();
private:
    float value_;
    int precision_;
    int int_part_;
};