#include <iostream>
#include <fstream>
#include <string>
#include <TemplateText.hpp>

#include "XMLBuilder.hpp"

int main() {
    std::ifstream in("../Input/pattern.txt");
    std::ofstream out("../Report/PenguinTest.txt");
    TemplateText template_text;

    std::string input;
    while (std::getline(in, input)) {
        template_text.inputStringHandler(input);
    }
    in.close();
    try {
        XMLBuilder xml_doc("../Input/arguments.XML");

        in.open("../Input/arguments.XML");

        for (auto &token : template_text.parsed_text) {
            if (token.simple_text) continue;
            else {
                if (token.getUsageStatus()) {
                    if (!xml_doc.getValue(token.toString()).empty()) {
                        token.argumentMatch(xml_doc.getValue(token.toString()));
                    } else {
                        std::cerr << "Argument not used: " << token.toString() << '\n' << '\n';
                        return -1;
                    }
                } else {
                    if (!xml_doc.getValue(token.toString()).empty()) {
                        token.argumentMatch(xml_doc.getValue(token.toString()));
                    }
                }
            }
        }

        for (auto &token : template_text.parsed_text) {
            if (token.getUsageStatus()) {
                out.close();
                out.open("../Report/PenguinTest.txt");
                in.close();
                out.close();
                std::cerr << "Argument not used: " << token.toString() << '\n' << '\n';
                return 0;
            }
            out << token;
        }
        in.close();
        out.close();
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    return 0;
}
