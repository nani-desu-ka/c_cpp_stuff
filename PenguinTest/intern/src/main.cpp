#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "TextToken.hpp"

std::vector<TextToken> parsed_text;
std::unordered_map<std::string, int> token_place;

void inputStringHandler(std::string input) {
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

int main() {
    std::ifstream in("../Input/pattern.txt");
    std::ofstream out("../Report/PenguinTest.txt");
    std::string input;

    while (std::getline(in, input)) {
        inputStringHandler(input);
    }
    in.close();
    in.open("../Input/arguments.txt");
    std::string arg_name;
    std::string argument;
    while (in >> arg_name >> argument) {
        if (token_place.find(arg_name) == token_place.end()) {
            out.close();
            out.open("../Report/PenguinTest.txt");
            out << "Incorrect argument used: " << arg_name << '\n' << '\n';
            return 0;
        } else {
            parsed_text[token_place[arg_name]].argumentMatch(argument);
        }
    }
    for (const auto &token : parsed_text) {
        if (token.getUsageStatus()) {
            out.close();
            out.open("../Report/PenguinTest.txt");
            out << "Argument not used: " << token << '\n' << '\n';
            return 0;
        }
        out << token;
    }
    in.close();
    out.close();
    return 0;
}
