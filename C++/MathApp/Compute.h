// Computer class
#ifndef _COMP_H__
#define _COMP_H__

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Compute {
private:
    // private data
    string expression;
    double value;
    // private function
    void ConvertEnd(const string & front, vector<char> & end);
    float Compute(const vector<char> & end);
    bool IsOp(char ch);
    bool IsBig(char ch0, char ch1);
    int FindValue(float & value, const vector<char> & arr, int star);
    float TopFloat(stack<float> & s);
    float SigComp(float x, float y, char op);
public:
    Compute(const string & exp) : expression(exp) {};
    ~Compute() {};

    void exp() { cout << expression; };
    void val() { cout << value; };
}

#endif