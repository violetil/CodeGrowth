#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void get_next(string T, int next[]);

int main() {
    string str;
    int next[100];

    printf("Please enter the mode string:");
    getline(cin, str);
    get_next(str, next);

    for (int i = 0; i <= str.length(); i++) {
        cout << next[i] << " ";
    }
    cout << endl;
    return 0;
}

void get_next(string T, int next[]) {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < T.length()) {
        if (j == -1 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}