#include <iostream>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

// Function to evaluate postfix expressions
int evaluatePostfix(const string& expression) {
    stack<int> s;
    string::const_iterator it = expression.begin();
    
    while (it != expression.end()) {
        if (isdigit(*it)) {
            s.push(*it - '0');
        } else if (*it == ' ') {
            // Skip spaces
        } else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            switch (*it) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                default:
                    cerr << "Unknown operator: " << *it << endl;
                    exit(EXIT_FAILURE);
            }
        }
        ++it;
    }
    return s.top();
}

// Function to evaluate prefix expressions
int evaluatePrefix(const string& expression) {
    stack<int> s;
    string reversedExpr(expression.rbegin(), expression.rend());
    string::const_iterator it = reversedExpr.begin();
    
    while (it != reversedExpr.end()) {
        if (isdigit(*it)) {
            s.push(*it - '0');
        } else if (*it == ' ') {
            // Skip spaces
        } else {
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();
            switch (*it) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                default:
                    cerr << "Unknown operator: " << *it << endl;
                    exit(EXIT_FAILURE);
            }
        }
        ++it;
    }
    return s.top();
}

int main() {
    string expression;
    char type;

    cout << "Enter the type of expression (p for postfix, f for prefix): ";
    cin >> type;
    cin.ignore(); // to ignore the newline character left by cin

    cout << "Enter the expression (with spaces between numbers and operators): ";
    getline(cin, expression);

    try {
        if (type == 'p') {
            int result = evaluatePostfix(expression);
            cout << "Postfix expression result: " << result << endl;
        } else if (type == 'f') {
            int result = evaluatePrefix(expression);
            cout << "Prefix expression result: " << result << endl;
        } else {
            cerr << "Invalid expression type. Use 'p' for postfix and 'f' for prefix." << endl;
        }
    } catch (const exception& e) {
        cerr << "Error evaluating expression: " << e.what() << endl;
    }

    return 0;
}

