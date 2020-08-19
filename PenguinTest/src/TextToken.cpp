#include "TextToken.hpp"
#include <iostream>

TextToken::TextToken(std::string variable_name, bool simple_text, bool token_usage) : variable_name_(std::move(variable_name)),
                                                                                      simple_text_(simple_text),
                                                                                      must_use_(token_usage) {}

void TextToken::argumentMatch(std::string argument_value) {
    simple_text_ = true;
    variable_name_ = std::move(argument_value);
    must_use_ = false;
}

bool TextToken::getUsageStatus() const {
    return must_use_;
}

std::ostream &operator<<(std::ostream &out, const TextToken &value) {
    if (!value.simple_text_ && !value.must_use_) {
        out << "";
        return out;
    }
    out << value.variable_name_;
    return out;
}