#include "lexer.h"
/**
  * @brief Tokenizes input into
  */
/*
       Token types:
        Identifier
            x, color, MAX_VALUE, etc...
       Keyword
            if, while, for, return, etc...
       Separator
            {}, (), ;, ,,
       Operator
            +, -, /, *, <, >, =
       Literal
            true, "Hello", 6.02f
       Comment
            //
            / * * /
   */
Lexer::Lexer(std::string input)
    : untokened(input)
{
}

void Lexer::tokenize()
{
}