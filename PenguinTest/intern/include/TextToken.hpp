#pragma once
#include <string>

class TextToken {
public:
    explicit TextToken(std::string, bool = true, bool = false);
    void argumentMatch(std::string);
    [[nodiscard]] bool getUsageStatus() const;
    friend std::ostream &operator<<(std::ostream &, const TextToken &);
private:
    bool must_use_, simple_text_;
    std::string variable_name_;
};
