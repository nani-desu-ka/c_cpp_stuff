#include "SimpleFraction.hpp"
#include "help_functions.hpp"

SimpleFraction::SimpleFraction() {
    this->upper_ = 1;
    this->lower_ = 1;
}

SimpleFraction::SimpleFraction(int upper, int lower) {
    upper_ = upper;
    lower_ = lower;
}

SimpleFraction SimpleFraction::operator*(int value) {
    upper_ *= value;
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator/(int value) {
    if (value == 0) {
//        place for exception
        return SimpleFraction();
    }
    lower_ *= value;
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator+(int value) {
    if (value == 0) {
//        place for exception
        return SimpleFraction();
    }
    value *= lower_;
    upper_ += value;
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator-(int value) {
    if (value == 0) {
//        place for exception
        return SimpleFraction();
    }
    value *= lower_;
    upper_ -= value;
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator^(int power) {
    if (power == 0) {
        return SimpleFraction();
    }
    int start_upper = upper_;
    int start_lower = lower_;
    for (int i = 1; i < power; i++) {
        upper_ *= start_upper;
        lower_ *= start_lower;
    }
    this->relax();
    return *this;
}

void SimpleFraction::relax() {
    int start_upper = abs(upper_);
    int start_lower = abs(lower_);
    while (start_upper != 0 && start_lower != 0) {
        if (start_upper > start_lower) {
            start_upper %= start_lower;
        } else {
            start_lower %= start_upper;
        }
    }
    upper_ /= (start_upper + start_lower);
    lower_ /= (start_upper + start_lower);
}

SimpleFraction SimpleFraction::operator*(SimpleFraction value) {
    upper_ *= value.getUpper();
    lower_ *= value.getLower();
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator/(SimpleFraction value) {
    upper_ *= value.getLower();
    lower_ *= value.getUpper();
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator+(SimpleFraction value) {
    upper_ *= value.getLower();
    upper_ += value.getUpper() * lower_;
    lower_ *= value.getLower();
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator-(SimpleFraction value) {
    upper_ *= value.getLower();
    upper_ -= value.getUpper() * lower_;
    lower_ *= value.getLower();
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator^(SimpleFraction power) {
    if (power.getUpper() == 0) {
        return SimpleFraction();
    }
    int start_upper = upper_;
    int start_lower = lower_;
    for (int i = 1; i < power.getUpper(); i++) {
        upper_ *= start_upper;
        lower_ *= start_lower;
    }
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator*=(SimpleFraction value) {
    return *this * value;
}

SimpleFraction SimpleFraction::operator/=(SimpleFraction value) {
    return *this / value;
}

SimpleFraction SimpleFraction::operator+=(SimpleFraction value) {
    return *this + value;
}

SimpleFraction SimpleFraction::operator-=(SimpleFraction value) {
    return *this - value;
}

SimpleFraction SimpleFraction::operator*(CustomFloat value) {
    *this *= decimalToFraction(value);
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator/(CustomFloat value) {
    *this /= decimalToFraction(value);
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator+(CustomFloat value) {
    *this += decimalToFraction(value);
    this->relax();
    return *this;
}

SimpleFraction SimpleFraction::operator-(CustomFloat value) {
    *this -= decimalToFraction(value);
    this->relax();
    return *this;
}

int SimpleFraction::getUpper() const {
    return upper_;
}

int SimpleFraction::getLower() const {
    return lower_;
}

std::ostream& operator<<(std::ostream &out, const SimpleFraction &value) {
    if (value.getLower() == 1) out << value.getUpper();
    else if (value.getLower() == 0) out << "inf (division by zero)";
    else out << value.getUpper() << '/' << value.getLower();
    return out;
}