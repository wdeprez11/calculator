#include <iostream>

class Input {
private:
    std::string input;

public:
};

/* Character sets:
   [+\-/*^%]
   (\\d+(\\.\\d+)?)* --- All numbers (and decimals)
*/

// (\\((\\s*\\d+\\s*|\\s*[-+*/]+\\s*){1}\\))
// XOR
// (\\s*(\\d+\\s*)[-+*/]\\s*)

// Valid input:
// (5 + 5) -- ignore parenthesis, except for order of operations
// (+ 5 5) -- require parenthesis, only one operator per parenthesis pair
// (5+5) -- same as (5 + 5)
// 5+5 -- use regular order of operations
// 5 + 5
