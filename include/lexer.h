#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
class Lexer {
private:
    std::string untokened;
    vector<Token> tokens;

public:
    Lexer(std::string input);
    void tokenize();
};
#endif // LEXER_H
