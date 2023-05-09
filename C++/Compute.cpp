#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// Convert the infix expression entered by the 
// user into a suffix expression
void ConvertEnd(const string & front, vector<char> & end);

// Calculate the final value based on the suffix 
// expression from the ConvertEnd()
float Compute(const vector<char> & end);

// Return ture if ch equals 
//   '+'   '-'   '*'   '/'   '('   ')'
bool IsOp(char ch);

// Return ture if the proprity of ch0 is greater than ch1
bool IsBig(char ch0, char ch1);

// Read the number or decimal character after start and 
// convert it to a numberical value
int FindValue(float & value, const vector<char> & arr, int star);

// Return the top value in float stack 
// if the stack is not empty
float TopFloat(stack<float> & s);

// Preform a specified four arithmetic 
// operation on x and y
float SigComp(float x, float y, char op);

int main() {
    string front;
    vector<char> end;

    // Read input
    cout << "Enter the expression(q to quit): ";
    while (getline(cin, front) && front[0] != 'q') {
        if (!isdigit(front[0])) {
            cout << "Please enter the correct expression:";
            end.clear(); continue;
        }

        // Conver to the end format
        ConvertEnd(front, end);

        // Calculate the value
        cout << setiosflags(ios::fixed) << setprecision(2);
        cout << Compute(end) << endl;
        end.clear();
        cout << "Next expression(q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}

void ConvertEnd(const string & front, vector<char> & end) {
    stack<char> s;

    for (int i = 0; i < front.length(); i++) {
        if (isdigit(front[i]) || front[i] == '.') end.push_back(front[i]);
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

float Compute(const vector<char> & end) {
    // Compute the value through the end format
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
    } else { cout << "Error!\n"; return 0; }
}

int FindValue(float & value, const vector<char> & arr, int start) {
    int i, j, p; value = 0;
    bool isDecimal = false;
    float integer = 0, decimal = 0;

    for (i = start; i < arr.size() && (isdigit(arr[i]) || arr[i] == '.' || arr[i] == ' '); i++) {
        if (arr[i] == ' ') break;
        if (arr[i] == '.') { isDecimal = true; break; }
        integer = (integer * 10) + (arr[i] - '0');         
    }
    if (isDecimal == true) {
        for (j = i + 1, p = -1; j < arr.size() && isdigit(arr[j]); j++) {
            decimal += (arr[j] - '0') * pow(10.0, p);
            p--;
        }
    }
    value = integer + decimal;

    return isDecimal ? j - start - 1 : i - start - 1;
}

float TopFloat(stack<float> & s) {
    if (s.empty()) {
        cout << "Error!\n";
        return 0;
    } else {
        float temp = s.top(); s.pop();
        return temp;
    }
}

float SigComp(float x, float y, char op) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        default: cout << "Error!\n";
            return 0;
    }
}