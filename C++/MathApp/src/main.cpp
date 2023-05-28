#include <iostream>
#include "Computer.h"
#include <string>

int main() {
    Computer count; // Class statement
    std::string str;

    std::getline(cin, str);
    count.get(str);
    count.show();

    return 0;
}