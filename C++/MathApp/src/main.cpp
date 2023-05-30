#include <iostream>
#include "Computer.h"
#include <string>

int main() {
    Computer count; // Class statement
    std::string str;

    std::cout << ">>> ";
    while (std::getline(std::cin, str)) {
        count.get(str);
        count.compute();
        count.show();
        std::cout << ">>> ";
    }
    return 0;
}