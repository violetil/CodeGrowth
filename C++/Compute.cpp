#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void ConvertEnd(const string & front, vector<char> & end);
int Compute(const vector<char> & end);
bool IsOp(char ch);
bool IsBig(char ch0, char ch1);
int FindValue(int & value, const vector<char> & arr, int star);
int TopFloat(stack<int> & s);
int SigComp(int x, int y, char op);

int main() {
    string front;
    vector<char> end;

    // Read input
    cout << "Enter the expression: ";
    while (getline(cin, front))

    // Conver to the end format
    ConvertEnd(front, end);

    // Compute the value
    cout << Compute(end) << endl;

    return 0;
}

void ConvertEnd(const string & front, vector<char> & end) {
    stack<char> s;

    for (int i = 0; i < front.length(); i++) {
        if (isdigit(front[i])) end.push_back(front[i]);
        else if (IsOp(front[i])) {
            end.push_back(' ');
            if (s.empty()) s.push(front[i]);
            else if (front[i] == ')') {
                while (s.top() != '(') {
                    end.push_back(s.top()); s.pop();
                } 
                s.pop();
            } else {
                if (IsBig(front[i], s.top())) s.push(front[i]);
                else {
                    while (!s.empty() && s.top() != '(' && !IsBig(front[i], s.top())) {
                        end.push_back(s.top()); s.pop();
                    }
                    s.push(front[i]);
                }
            }
        }
    }
    while (!s.empty()) {
       end.push_back(s.top()); s.pop();
    }
}

bool IsOp(char ch) {
    return (ch == '+') || (ch == '-') 
        || (ch == '*') || (ch == '/')
        || (ch == '(') || (ch == ')');
}

bool IsBig(char ch0, char ch1) {
    switch (ch0) {
        case '+':
        case '-': return false;
            break;
        case '/':
        case '*': return (ch1 == '+') || (ch1 == '-');
            break;
        case '(': return (ch1 == '+') || (ch1 == '-')
                        || (ch1 == '*') || (ch1 == '/');
            break;
        default: cout << "Error!" << endl;
            return false;
    }
}

int Compute(const vector<char> & end) {
    // Compute the value throught the end format
    stack<float> s;

    for (int i = 0; i < end.size(); i++) {
        if (isdigit(end[i])) {
            float temp = 0;
            i += FindValue(temp, end, i);
            s.push(temp);
        } else if (IsOp(end[i])) {
            s.push(SigComp(TopFloat(s), TopFloat(s), end[i]));
        }
    }

    if (!s.empty()) {
        return s.top();
    } else cout << "Error!\n";
}

int FindValue(float & value, const vector<char> & arr, int start) {
    int i, j; value = 0;
    bool isDecimal = false;
    float integer = 0, decimal = 0;

    for (i = start; i < arr.size() && (isdigit(arr[i]) || arr[i] == '.'); i++) {
        integer = (integer * 10) + (arr[i] - '0');         
        if (arr[i] == '.') { isDecimal = true; break; }
    }
    if (isDecimal == true) {
        for (j = i + 1; j < arr.size() && isdigit(arr[i]); j++) {
            
        }
    }
    value = integer + decimal;

    return i - start - 1;
}

int TopFloat(stack<int> & s) {
    if (s.empty()) {
        cout << "Error!\n";
        return 0;
    } else {
        int temp = s.top(); s.pop();
        return temp;
    }
}

int SigComp(int x, int y, char op) {
    int value = 0;

    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default: cout << "Error!\n";
            return 0;
    }
}