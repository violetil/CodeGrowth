// Computer.cpp -- implementing the Compter class
#include <iostream>
#include "Computer.h"

void Computer::get(const std::string & exp)
{
    expression = exp;
}

void Computer::show()
{
    std::cout << expression;
}