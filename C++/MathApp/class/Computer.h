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
    int value;
public:
    void get(const std::string & exp);
    void compute();
    void show();
};

#endif