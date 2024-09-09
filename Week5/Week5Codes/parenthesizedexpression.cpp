#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];
       
        if (ch == '(') {
            parenthesesStack.push(ch);
        }
       
        else if (ch == ')') {
            
            if (parenthesesStack.empty()) {
                return false;
            }
            
            parenthesesStack.pop();
        }
    }

   
    return parenthesesStack.empty();
}

int main() {
    std::string expression;

    std::cout << "Enter a parenthesized expression: ";
    std::getline(std::cin, expression);

    if (isValidParentheses(expression)) {
        std::cout << "The expression has properly matching parentheses." << std::endl;
    } else {
        std::cout << "The expression does not have properly matching parentheses." << std::endl;
    }

    return 0;
}
