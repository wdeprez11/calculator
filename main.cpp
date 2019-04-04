#include "header.h"
#include <iostream>

int main()
{
    Precise p1(2);
    Precise p2(3);

    std::cout << (p1 + p2).GetSize() << std::endl;
}
