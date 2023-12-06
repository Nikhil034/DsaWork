#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> stack;

    for (char bracket : s) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(bracket);
        } else {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((bracket == ')' && top != '(') ||
                (bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    std::string input = "{[()]}";
    if (isValid(input)) {
        std::cout << "The input string is valid.\n";
    } else {
        std::cout << "The input string is not valid.\n";
    }
    return 0;
}
