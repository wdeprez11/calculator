#ifndef LEXER_H
#define LEXER_H
#include <fstream>
#include <string>
#include <vector>
class Lexer {
private:
    std::string untokened;

public:
    Lexer(std::ifstream inputFile);
    void tokenize();
};
#endif // LEXER_H
