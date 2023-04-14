#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

bool IsLeft(char lch); // Return true if lch is begin of sign
bool IsRight(char rch); // Return true if rch is end of sign
void CheckBlance(std::stack<char> & Stack, std::string in, char & err);
void PrintMatchSign(char sig);
void Error(char ch);
bool SignMatch(char lch, char rch);
int main() {
    // Using declear area
    using std::string; 
    using std::cin;
    using std::getline;
    using std::cout;

    // Main coding area
    // Declear
    string input; // Store the input code to check sign blance
    std::stack<char> signStack; // Store signs
    char err = 'E';
    // Coding
    while (std::getline(cin, input) && input[0] != '.')
    {       // Continue get input line until meet "."
       CheckBlance(signStack, input, err); 
    }
    if (!signStack.empty()) {
      cout << "NO\n";
      PrintMatchSign(signStack.top());
      return 0;
    }
    cout << "YES"; 
    return 0;
}

bool IsLeft(char lch) {
   return (lch == '/') || (lch == '(')
      || (lch == '[') || (lch == '{');   
}
bool IsRight(char rch) {
   return (rch == '*') || (rch == ')')
      || (rch == ']') || (rch == '}');
}
void PrintMatchSign(char sig) {
   if (IsLeft(sig)) { 
      switch (sig) {
      case '/':std::cout << "/*-?"; break;
      case '(':std::cout << "(-?"; break;
      case '[':std::cout << "[-?"; break;
      case '{':std::cout << "{-?"; break;
      }
   } else if (IsRight(sig)) {
      switch (sig) {
      case '*':std::cout << "?-*/"; break;
      case ')':std::cout << "?-)"; break;
      case ']':std::cout << "?-]"; break;
      case '}':std::cout << "?-}"; break;
      }
   }
}
void CheckBlance(std::stack<char> & Stack, std::string in, char & err) {
   int i = 0;
   for (i = 0; in[i]; i++)
   {
      // Stack push if sign is left
      if (IsLeft(in[i])) {
         // '/'
         if (in[i] == '/') {
            if (in[i + 1] && in[i + 1] == '*')
            {
               Stack.push(in[i++]);
            }
         }
         // else
         else Stack.push(in[i]);
      } 
      // Stack pop if sign is right and left right match
      // and stack is not empty
      else if (IsRight(in[i])) {
         if (in[i] == '*') {
            if (in[i + 1] && in[i + 1] == '/') {
               if (Stack.empty()) {std::cout << "NO\n"; PrintMatchSign(in[i]);
               exit(0);}
               else {
                  if (SignMatch(Stack.top(), in[i])) {Stack.pop();}
                  else {std::cout << "NO\n"; PrintMatchSign(in[i]); exit(0);}
               }
            }
         } else {
            if (Stack.empty()) {std::cout << "NO\n"; PrintMatchSign(in[i]);
            exit(0);}
            else {
               if (SignMatch(Stack.top(), in[i]) && err == 'E') {Stack.pop();}
               else if (err == 'E') {
                  err = in[i];
               } else {
                  if (SignMatch(Stack.top(), in[i])) {std::cout << "NO\n"; PrintMatchSign(err); exit(0);}
                  else {std::cout << "NO\n"; PrintMatchSign(Stack.top()); exit(0);}
               }
            }
         }
      }
   }
}
void Error(char ch) {
   std::cout << "Error, not have or not have right left sign ";
   switch (ch) {
      case '*':std::cout << "/*"; break;
      case ')':std::cout << "("; break;
      case ']':std::cout << "["; break;
      case '}':std::cout << "{"; break;
   }
   std::cout << std::endl;
}
bool SignMatch(char lch, char rch) {
   switch (lch) {
      case '/':return rch == '*'; break;
      case '(':return rch == ')'; break;
      case '[':return rch == ']'; break;
      case '{':return rch == '}'; break;
      default: return false;
   }
}