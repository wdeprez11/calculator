#include <iostream>
#include "operation.h"

#define PI    3.1415926535897932384626433
#define Euler 2.7182818284590452353602874

int main()
{
    /*
     * Arithmetic Rules:
     *
     * Valid Operands:
     * 0-9, PI, Euler
     *
     * Valid Operators:
     * +, -, *, /, ^
     *
     * Unary Operators:
     * -
     *
     * Valid Punctuation:
     * (1, 2) * 3 yields (3, 6)
     *
     * Other:
     * Grouping with parenthesis:
     * All operations found within parenthesis will be calculated first
     *
     */
    
    /*
     * Input: "(5 * (5 + 3)^3)^2"
     * *find two sets of parenthesis,
     * calculate first set
     * look for highest priority operator (caret in this case)
     * 8^3 yields 512
     * (5 * 512)^2
     * calculate within parenthesis
     * 5 * 512 yields 2560
     * 2560^2 yields 6,553,600
     */
    
    operation complex("(5 * (5 + 15))^2");
    //std::cout << complex;
    
    /*
    operation operation2;
    operation operation4;
    
    std::cout << operation2;
    std::cout << operation4;
     */
    
    /*
    
    auto add      = [](int n1, int n2) { return n1 + n2; };
    auto subtract = [](int n1, int n2) { return n1 + n2; };
    auto multiply = [](int n1, int n2) { return n1 + n2; };
    auto divide   = [](int n1, int n2) { return n1 + n2; };
    
    std::cout << "Please enter a number, operator, then another number" << std::endl;
    
    int  operand1, operand2;
    char operator1;
    
    std::cin >> operand1 >> operator1 >> operand2;
    
    switch (operator1) {
        case '+':
            std::cout << "Result: " << add(operand1, operand2) << std::endl;
            break;
        case '-':
            std::cout << "Result: " << subtract(operand1, operand2) << std::endl;
            break;
        case '*':
            std::cout << "Result: " << multiply(operand1, operand2) << std::endl;
            break;
        case '/':
            std::cout << "Result: " << divide(operand1, operand2) << std::endl;
            break;
        default:
            std::cout << "Unrecognized Operator: " << operator1 << std::endl;
            break;
    }
    
     */
    return 0;
}