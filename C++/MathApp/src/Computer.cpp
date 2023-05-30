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

/** Return true if the expression e is a number. */
static bool isNumber(const std::string& e) {
    bool sym = false, num = false;
    for (int i = 0; i < e.size(); i++) {
        if (!sym && !num && (e[i] == '+' || e[i] == '-')) {
            sym = true;
        } else if (!sym && !num && isdigit(e[i])) {
            break;
        } else if (sym && num) {
            if (!isdigit(e[i]) && e[i] != ' ' && e[i] != '.') {
                num = false;
            }
        }
    } 
    if (sym && num) return true;
    return false;
}

/** Find the positon of reverse bracket corresponding to the position 
 *  start in the experssion and return. 
*/
static int nextPos(const std::string& e, int start) {
    stack<char> s;
    int next = start;
    bool isRight = false;               // Whether is right bracket.

    if (e[start] != '(') {
        std::cout << "Error bracket front!\n";
        return next;
    }

    for (next = start + 1; next < e.size(); next++) {
        if (s.empty() && e[next] == ')') {
            isRight = true; break;
        } else if (e[next] == ')' && !s.empty()) {
            s.pop();
        } else if (e[next] == '(') {
            s.push(e[next]);
        }
    }
    if (!isRight) {
        std::cout << "Error bracket behind!\n"; next = start;
    }
    return next;
}

/** Find the expression in parentheses corresponding to start and return. */
static std::string findString(const std::string& e, int start, int rear) {
    std::string res;
    for (int i = start + 1; i < rear; i++) {
        res.push_back(e[i]);
    }
    return res;
}

/** Convert the incoming string into a suffix expression and return. */
static std::string convertExpre(const std::string& e) {
    stack<char> s;
    std::string res;

    if (isNumber(e)) {
        res = e; return res;
    }

    for (int i = 0; i < (int)e.size(); i++) {
        if (e[i] == ' ') {
            continue;
        } else if (isdigit(e[i]) || e[i] == '.') {      // Is a number or decimal point.
            res.push_back(e[i]); 
        } else if (isSymbol(e[i])) {                    // Is a arithmetic symbol.
            res.push_back(' ');
            if (s.empty()) {                                // Stack is empty.
                s.push(e[i]);
            } else if (isGreater(e[i], s.top())) {          // Greater than the top of stack.
                s.push(e[i]);
            } else {                                        // Not greater
                while (!s.empty() && !isGreater(e[i], s.top())) {
                    res.push_back(s.top()); res.push_back(' ');
                    s.pop();
                } s.push(e[i]);
            }
        } else if (e[i] == '(') {
            int next = nextPos(e, i);
            res += convertExpre(findString(e, i, next));
            i = next;
        } else { std::cout << "Error expression!\n"; }
    }

    while (!s.empty()) {
        res.push_back(' '); res.push_back(s.top());
        s.pop();
    }

    return res;
}

/** Convert infix expression e to suffix expression. */
static void convertExpre(std::string& eInfix, std::string& eSuffix) {
    // 1. Add to eSuffix if a number or decimal point.
    // 2. Push to stack if stack is empty or greater than the top of stack.
    //    Else add the top of stack to the eSuffix untill the top less the symbol.
    // 3. Meet the front bracket, find the first internal expression
    //    Use the recursion???     
    eSuffix = convertExpre(eInfix);
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
    // 1. Convert to suffix expression.
    // 2. Calculate the value.
    std::string suffix;
    convertExpre(expression, suffix);
    std::cout << suffix << endl;
}