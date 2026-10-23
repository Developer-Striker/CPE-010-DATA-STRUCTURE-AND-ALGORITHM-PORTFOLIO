#include <iostream>
#include <string>
#include "ListStack.h"

bool checkBalanceList(const std::string& expr) {
    ListStack<char> stack;
    
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

    std::cout << "======== LINKED LIST STACK ========\n\n";
    for (const auto& expr : expressions) {
        std::cout << "Expression: " << expr << " -> " 
                  << (checkBalanceList(expr) ? "Valid" : "Invalid") << "\n";
    }
    return 0;
}
