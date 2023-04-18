#include <iostream>
#include <string>

using namespace std;

void Get_Next(string Mstr, int next[]) {
    int i = 0, j = -1;
    // Inital value
    next[0] = -1;
    // Find the same front characters and plus one
    while (i < Mstr.length()) {
        if (j == -1 || Mstr[i] == Mstr[j]) {
            ++i; ++j; next[i] = j;
        } else { j = next[j]; }
    }
}

int main() {
    string mainStr, matchStr;
    int next[100];
    // Read main string and match string
    cout << "Enter the main string:";
    getline(cin, mainStr);
    cout << "Enter the match string:";
    getline(cin, matchStr);
    // Get the next array of match string
    Get_Next(matchStr, next);
    // Through the next array to compare
    int i = 0, j = 0;
    while (i < mainStr.length() && j < matchStr.length()) {
        if (mainStr[i] == matchStr[j]) j++;
        else j = next[j]; i++;
    }
    if (j >= matchStr.length()) { cout << "Find!\n"; }
    else { cout << "Not find!\n"; }
    return 0;
}