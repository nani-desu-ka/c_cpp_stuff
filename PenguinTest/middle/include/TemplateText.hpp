#pragma once
#include <vector>
#include <unordered_map>

class TemplateText {
private:
    class TextToken {
    public:
        explicit TextToken(std::string, bool = true, bool = false);
        void argumentMatch(std::string);
        [[nodiscard]] bool getUsageStatus() const;
        [[nodiscard]] std::string toString();
        bool simple_text;
    private:
        bool _must_use;
        std::string _variable_name;
    };

public:
    TemplateText();
    void inputStringHandler(std::string);
    friend std::ostream &operator<<(std::ostream &, TextToken &);
    std::vector<TextToken> parsed_text;
    std::unordered_map<std::string, int> token_place;
};