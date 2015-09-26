#include "Parser.h"
#include <regex>


string Parser::stringWithValidChars(string str){
    smatch match;
    regex regEx("[a-z_0-9]", regex_constants::icase);
    
    stringstream buffer;
    while (regex_search (str,match,regEx)) {
        for (auto x : match){
            buffer << x;
        }
        str = match.suffix().str();
    }
    return buffer.str();
}