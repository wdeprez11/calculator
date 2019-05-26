//
// Created by William on 5/24/2019.
//

#include <algorithm>
#include <cmath>
#include <regex>
#include "comfy.h"

void remove_spaces(std::string &string) {
    string.erase(remove(string.begin(), string.end(), ' '), string.end());
}

bool is_operator(char potential_operator) {
    switch (potential_operator) {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        default:
            return false;
    }
}

int parse_int(std::string &int_string) {
    int result_num = 0;
    
    for (int string_index = int_string.size() - 1, place_value = 0; string_index >= 0; string_index--, place_value++) {
        result_num += (int_string[string_index] - 48) * (int)pow(10, place_value);
    }
    
    return result_num;
}

bool is_valid_eqn(std::string &operation) {
    std::regex r(R"(\d+\s*(\+|\-|\*|\/)\s*\d+)");
    return regex_match(operation, r);
}
