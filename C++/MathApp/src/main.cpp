#include <iostream>
#include "Computer.h"
#include <string>

int main() {
    Computer count; // Class statement
    std::string str;

    std::cout << "Enter an expression: ";
    while (std::getline(cin, str)) {
        count.get(str);
        count.compute();
        std::cout << "Next: ";
    }
    return 0;
}