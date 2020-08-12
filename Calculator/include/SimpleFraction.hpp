#pragma once
#include <iostream>
#include "CustomFloat.hpp"

class SimpleFraction {
public:
    explicit SimpleFraction();
    explicit SimpleFraction(int, int);

    SimpleFraction operator+(int);
    SimpleFraction operator-(int);
    SimpleFraction operator*(int);
    SimpleFraction operator/(int);
    SimpleFraction operator^(int);

    SimpleFraction operator+(CustomFloat);
    SimpleFraction operator-(CustomFloat);
    SimpleFraction operator*(CustomFloat);
    SimpleFraction operator/(CustomFloat);

    SimpleFraction operator+(SimpleFraction);
    SimpleFraction operator-(SimpleFraction);
    SimpleFraction operator*(SimpleFraction);
    SimpleFraction operator/(SimpleFraction);
    SimpleFraction operator^(SimpleFraction);
    SimpleFraction operator*=(SimpleFraction);
    SimpleFraction operator-=(SimpleFraction);
    SimpleFraction operator+=(SimpleFraction);
    SimpleFraction operator/=(SimpleFraction);

    [[nodiscard]] int getUpper() const;
    [[nodiscard]] int getLower() const;

    friend std::ostream& operator<<(std::ostream &, const SimpleFraction &);

    void relax();
private:
    int upper_;
    int lower_;
};