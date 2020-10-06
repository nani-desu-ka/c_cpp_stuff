#include <XMLBuilder.hpp>
#include <fstream>

XMLBuilder::XMLBuilder(const std::string &input_xml) {
    std::ifstream in(input_xml);
    if (in.fail()) throw std::ios_base::failure("Unable to open the file");
    std::string input;
    while (std::getline(in, input)) {
        struct XMLSection temp_field = XMLStringParser(input);
        if (temp_field.value.empty() && temp_field.field.empty()) {
            throw std::invalid_argument("No field or value provided");
        }
        _fields[temp_field.field] = temp_field.value;
    }
    in.close();
}

struct XMLBuilder::XMLSection XMLBuilder::XMLStringParser(std::string unparsed_string) {
    std::string field;
    std::string value;
    bool field_found = false;
    for (int i = 0; i < unparsed_string.length(); i++) {
        if (unparsed_string[i] == '<') {
            while (unparsed_string[i + 1] != '>') {
                if (i + 1 >= unparsed_string.length()) {
                    throw std::out_of_range("Wrong string format: " + unparsed_string);
                }
                field += unparsed_string[++i];
                if (unparsed_string[i + 1] == '>') {
                    field_found = true;
                    i++;
                    break;
                }
            }
        }
        if (field_found) {
            while (unparsed_string[i + 1] != '<') {
                if (i + 1 >= unparsed_string.length()) {
                    throw std::out_of_range("Wrong string format: " + unparsed_string);
                }
                value += unparsed_string[++i];
            }
            break;
        }
    }
    if (field_found) {
        struct XMLSection parsed_section;
        parsed_section.field = field;
        parsed_section.value = value;
        return parsed_section;
    } else {
        throw std::invalid_argument("Not XML format: " + unparsed_string);
    }
}

std::string XMLBuilder::getValue(const std::string &field_name) {
    if (_fields.find(field_name) != _fields.end()) return _fields[field_name];
    else return "";
}