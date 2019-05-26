//
// Created by William on 5/24/2019.
//

#ifndef UNTITLED_OPERATION_H
#define UNTITLED_OPERATION_H


#include <string>
#include <ostream>

class operation {
private:
    int operand1, operand2;
    char operator1;
    std::string operation_string;
    

public:
    operation();
    operation(std::string operation);
    
    int getOperand1() const;
    
    int getOperand2() const;
    
    char getOperator1() const;
    
    const std::string &getOperationString() const;
    
    friend std::ostream &operator<<(std::ostream &os, const operation &operation);
    
    class token {
    private:
        std::string type;
        char value;
    
    public:
        token(std::string type, char value);
        
        friend std::ostream &operator<<(std::ostream &os, const token &token);
    };
    
};


#endif //UNTITLED_OPERATION_H
