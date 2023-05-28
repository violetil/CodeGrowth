// Computer.h -- Computer class interface
// Input the expression and calculate the value
#ifndef COMPUTER_H_
#define COMPUTER_H_

#include <string>
using namespace std;

class Computer
{
private:
    std::string expression;
    double value;
public:
    /** Get the expression. */
    void get(const std::string& exp) { expression = exp; }

    /** Calculate the value of expression and store to value. */
    void compute();

    /** Print the value. */
    void show();
};

#endif