/**
  * @author William Deprez
  * @version 0.1
  * @date
  * @bug KNOWN_BUGS
  *
  * @warning WARNING
  * @copyright GNU General Public License v3.0
  * @mainpage Calculator
  * @section intro_sec Introduction
  * Introduction goes here!
  * @section compile_sec Building Calculator
  * Different ways to compile
  * @subsection Step1 Make
  * Use make...
  *
  */
#include "header.h"
#include <iostream>

int main()
{
    Precise p1(2);
    Precise p2(3);

    std::cout << (p1 + p2).GetSize() << std::endl;
    return 0;
}
