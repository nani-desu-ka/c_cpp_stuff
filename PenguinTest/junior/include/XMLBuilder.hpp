#pragma once
#include <string>
#include <unordered_map>

class XMLBuilder {
private:
    struct XMLSection {
        std::string field = "";
        std::string value = "";
    };
public:
    explicit XMLBuilder(const std::string &);
    static XMLSection XMLStringParser(std::string);
    [[nodiscard]] std::string getValue(const std::string &);
private:
    std::unordered_map<std::string, std::string> _fields;
};