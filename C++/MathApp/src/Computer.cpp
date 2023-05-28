/** Computer.cpp -- implementing the Compter class. **/

#include <iostream>
#include "Computer.h"
#include <cstring>
#include <stack>
#include <iomanip>

/** Return true if ch is an arithmetic symbol. */
static bool isSymbol(char ch) {
    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}

/** Return true if x greater than y. */
static bool isGreater(char x, char y) {
    switch(x) {
        case '+':
        case '-': return false;
        case '*': 
        case '/': return (y == '+') || (y == '-');
        default: std::cout << "Undefined arithmetic symbol comparation.\n";
            return false;
    }
}

/** Convert the incoming string into a suffix expression and return. */
static std::string converToSuf(std::string& e) {
    stack<char> s;
    std::string res;

    for (int i = 0; i < (int)e.size(); i++) {
        if (isdigit(e[i]) || e[i] == '.'){          // Is a number or decimal point.
            res.push_back(e[i]);
        } else if (isSymbol(e[i])) {                // Is a arithmetic symbol.
            if (s.empty()) {                            // Stack is empty.
                s.push(e[i]);
            } else if (isGreater(e[i], s.top())) {      // Greater than the top of stack.
                s.push(e[i]);
            } else {                                    // Not greater
                while (!s.empty() && !isGreater(e[i], s.top())) {
                    res.push_back(s.top());
                    s.pop();
                } s.push(e[i]);
            }
        }
    }
}

/** Convert infix expression e to suffix expression. */
static void convertExpre(std::string& eInfix, std::string& eSuffix) {
    // 1. Add to eSuffix if a number or decimal point.
    // 2. Push to stack if stack is empty or greater than the top of stack.
    //    Else add the top of stack to the eSuffix untill the top less the symbol.
    // 3. Meet the front bracket, find the first internal expression
    //    Use the recursion???     
}

/** Show the value of expression. */
void Computer::show()
{
    using namespace std;
    cout << setiosflags(ios::fixed) << setprecision(2);
    std::cout << expression << " = " << value
        << std::endl;
}

/** Calculate the value of expression. */
void Computer::compute() {

}