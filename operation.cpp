//
// Created by William on 5/24/2019.
//

#include <iostream>
#include <regex>
#include <stack>
#include <functional>
#include "operation.h"
#include "comfy.h"

operation::operation()
        : operand1(0)
          , operand2(0)
          , operator1(' ')
          , operation_string("null operation")
{};

operation::operation(std::string operation)
{
    remove_spaces(operation);
    
    this->operation_string = operation;
    
    std::stack<operation::token> result;
    
    auto isComma    = [](char value) { return value == ','; };
    auto isDigit    = [](char value) { return regex_match(std::string(1, value), std::regex(R"(\d)")); };
    auto isLetter   = [](char value) { return regex_match(std::string(1, value), std::regex(R"([a-z])")); };
    auto isOperator = [](char value) { return regex_match(std::string(1, value), std::regex(R"(\+|-|\*|\/|\^)")); };
    auto isLParen   = [](char value) { return value == '('; };
    auto isRParen   = [](char value) { return value == ')'; };
    
    std::for_each(operation.begin(), operation.end(), [&](char c) {
        if (isDigit(c)) {
            result.push(operation::token("Literal", c));
        } else if (isLetter(c)) {
            result.push(operation::token("Variable", c));
        } else if (isOperator(c)) {
            result.push(operation::token("Operator", c));
        } else if (isLParen(c)) {
            result.push(operation::token("Left Parenthesis", c));
        } else if (isRParen(c)) {
            result.push(operation::token("Right Parenthesis", c));
        } else if (isComma(c)) {
            result.push(operation::token("Function Argument Separator", c));
        }
    });
    
    while (!result.empty()) {
        std::cout << '\n' << result.top();
        result.pop();
    }
    
    
    //int result;
    
    /*
    remove_spaces(operation);
    
    std::string operand1, operand2;
    char        operator1;
    bool        operand1_complete = false;
    
    for (int i = 0; i < operation.size(); i++) {
        if (!operand1_complete) {
            operand1 += operation[i];
            if (is_operator(operation[i + 1])) {
                operand1_complete = true;
                operator1         = operation[i + 1];
                i++;
            }
        } else {
            operand2 = operation.substr(i, operation.size());
            break;
        }
        
        // bool operand1_complete = false;
        // if: not operand1_complete
        //     append to operand1 until operation[i] is an operator
        //     if: operation[i+1] is not an integer
        //         set operand1_complete true
        //         set operator1 = operation[i+1];
        // el:
        //     set operand2 to operation.substr(i, operation.size());
        //     break from loop
    }
     */
    
    /*
    std::cout << "operation: " << operation << '\n'
              << "operand1: " << operand1 << '\n'
              << "operand2: " << operand2 << '\n'
              << "operator1: " << operator1 << std::endl;
              */
    
    /*
    this->operand1         = parse_int(operand1);
    this->operand2         = parse_int(operand2);
    this->operator1        = operator1;
    this->operation_string = operation;
     */
}

operation::token::token(std::string type, char value)
{
    this->type  = type;
    this->value = value;
}

std::ostream &operator<<(std::ostream &os, const operation::token &token)
{
    os << "type: " << token.type << " value: " << token.value;
    return os;
}

int operation::getOperand1() const
{
    return operand1;
}

int operation::getOperand2() const
{
    return operand2;
}

char operation::getOperator1() const
{
    return operator1;
}

const std::string &operation::getOperationString() const
{
    return operation_string;
}

std::ostream &operator<<(std::ostream &os, const operation &operation)
{
    os << "operation=" << '{' << operation.operand1 << ", " << operation.operand2 << ", '" << operation.operator1
       << "', \""
       << operation.operation_string << '"' << '}' << std::endl;
    return os;
}

