#include <iostream>
#include <string>
#include "ArrayStack.h"

bool checkArrBalance(const std::string& expr) {
    ArrayStack<char> stack(expr.length()); 

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;
            
            char open = stack.pop();
            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    std::string expressions[] = {
        "(A+B)+(C-D)",
        "((A+B)+(C-D)",
        "((A+B)+[C-D])",
        "((A+B)+[C-D]}"
    };

    std::cout << "======== ARRAY STACK ========\n\n";
    for (const auto& expr : expressions) {
        std::cout << "Expression: " << expr << " -> " 
                  << (checkArrBalance(expr) ? "Valid" : "Invalid") << "\n";
    }
    return 0;
}