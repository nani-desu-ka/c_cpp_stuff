#include "TemplateText.hpp"

void TemplateText::inputStringHandler(std::string input) {
    std::string temp_token;
    for (int i = 0; i < input.length(); i++) {
        bool temp_usage = false;
        switch (input[i]) {
            case ' ':
                if (!temp_token.empty()) {
                    parsed_text.emplace_back(temp_token);
                    parsed_text.emplace_back(" ");
                    temp_token.clear();
                }
                continue;
            case '{':
                if (!temp_token.empty()) {
                    parsed_text.emplace_back(temp_token);
                    temp_token.clear();
                }
                i++;
                if (input[i] == '*') {
                    temp_usage = true;
                    i++;
                }
                while (input[i] != '}') {
                    temp_token += input[i];
                    i++;
                }
                token_place[temp_token] = parsed_text.size();
                parsed_text.emplace_back(temp_token, false, temp_usage);
                temp_token.clear();
                if (i + 1 < input.size() && input[i + 1] == ' ') {
                    parsed_text.emplace_back(" ");
                }
                continue;
            default:
                temp_token += input[i];
                continue;
        }
    }
    if (!temp_token.empty()) {
        parsed_text.emplace_back(temp_token);
        temp_token.clear();
    }
}

TemplateText::TemplateText() = default;

TemplateText::TextToken::TextToken(std::string variable_name, bool simple_text, bool token_usage) :
                                                                            _variable_name(std::move(variable_name)),
                                                                            simple_text(simple_text),
                                                                            _must_use(token_usage) {}

void TemplateText::TextToken::argumentMatch(std::string argument_value) {
    simple_text = true;
    _variable_name = std::move(argument_value);
    _must_use = false;
}

bool TemplateText::TextToken::getUsageStatus() const {
    return _must_use;
}

std::string TemplateText::TextToken::toString() {
    return _variable_name;
}

std::ostream &operator<<(std::ostream &out, TemplateText::TextToken &value) {
    std::string empty_one = "";
    if (!value.simple_text && !value.getUsageStatus()) {
        out << empty_one;
        return out;
    }
    out << value.toString();
    return out;
}