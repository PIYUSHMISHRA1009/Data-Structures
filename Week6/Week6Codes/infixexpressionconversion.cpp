#include <bits/stdc++.h>

using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (size_t i = 0; i < infix.length(); ++i) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c; // Add operands to output
        } else if (c == '(') {
            operators.push(c); // Push '(' to stack
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop '('
        } else if (isOperator(c)) {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }

    // Pop all the operators from the stack
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to reverse the string
string reverseString(const string& str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

// Function to convert infix expression to prefix
string infixToPrefix(const string& infix) {
    string reversedInfix = reverseString(infix);
    for (size_t i = 0; i < reversedInfix.length(); ++i) {
        char& c = reversedInfix[i];
        if (c == '(') {
            c = ')';
        } else if (c == ')') {
            c = '(';
        }
    }

    string postfix = infixToPostfix(reversedInfix);
    return reverseString(postfix);
}

// Main function
int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    getline(cin, infixExpression); // Use getline to read the entire line

    // Remove spaces from the input expression
    infixExpression.erase(remove_if(infixExpression.begin(), infixExpression.end(), ::isspace), infixExpression.end());

    string postfix = infixToPostfix(infixExpression);
    string prefix = infixToPrefix(infixExpression);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}
