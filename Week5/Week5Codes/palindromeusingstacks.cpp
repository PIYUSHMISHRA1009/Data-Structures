#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string str) {
    stack<char> charStack;
    
    for (int i = 0; i < str.length(); i++) {
        charStack.push(str[i]);
    }
    
   
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != charStack.top()) {
            return false; 
        }
        charStack.pop(); 
    }
    
    return true; 
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    for (int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    
    return 0;
}
