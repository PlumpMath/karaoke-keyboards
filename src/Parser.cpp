#include "Parser.h"
#include <regex>


string Parser::stringWithValidChars(string _str, string _reg){
    smatch match;
    regex regEx(_reg, regex_constants::icase);
    
    stringstream buffer;
    while (regex_search (_str,match,regEx)) {
        for (auto x : match){
            buffer << x;
        }
        _str = match.suffix().str();
    }
    return buffer.str();
}

bool Parser::isValidKey(int keyPressed, string _reg){
    string typedKey(1, keyPressed);
    if (regex_match(typedKey, regEx)) {
        return true;
    }else{
        return false;
    }
    
}