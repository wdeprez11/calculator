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

int main(int argc, char** argv)
{
    for (int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    //std::string call;
    //while (1) {
    //std::cin >> call;
    //}
    //return 0;
}
