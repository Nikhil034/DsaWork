#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

bool isValid(const std::string& s) {
    int count = 0;
    for (char c : s) {
        if (c == '(') {
            count++;
        } else if (c == ')') {
            count--;
            if (count < 0) {
                return false;
            }
        }
    }
    return count == 0;
}

void removeInvalidParenthesesHelper(const std::string& s, int index, int leftToRemove, int rightToRemove, std::string& current, std::unordered_set<std::string>& validExpressions) {
    if (index == s.length()) {
        if (leftToRemove == 0 && rightToRemove == 0 && isValid(current)) {
            validExpressions.insert(current);
        }
        return;
    }

    char currentChar = s[index];
    
    // Option 1: Remove the current character
    removeInvalidParenthesesHelper(s, index + 1, leftToRemove - (currentChar == '('), rightToRemove - (currentChar == ')'), current, validExpressions);
    
    // Option 2: Keep the current character
    current += currentChar;
    removeInvalidParenthesesHelper(s, index + 1, leftToRemove, rightToRemove, current, validExpressions);
    current.pop_back();
}

std::vector<std::string> removeInvalidParentheses(const std::string& s) {
    std::unordered_set<std::string> validExpressions;
    std::string currentExpression;
    
    // Count the number of left and right parentheses to remove
    int leftToRemove = 0, rightToRemove = 0;
    for (char c : s) {
        if (c == '(') {
            leftToRemove++;
        } else if (c == ')') {
            if (leftToRemove > 0) {
                leftToRemove--;
            } else {
                rightToRemove++;
            }
        }
    }
    
    removeInvalidParenthesesHelper(s, 0, leftToRemove, rightToRemove, currentExpression, validExpressions);
    
    return std::vector<std::string>(validExpressions.begin(), validExpressions.end());
}

int main() {
    std::string expression = "()())()";
    std::vector<std::string> validExpressions = removeInvalidParentheses(expression);

    std::cout << "Valid expressions after removing invalid parentheses:" << std::endl;
    for (const std::string& validExp : validExpressions) {
        std::cout << validExp << std::endl;
    }

    return 0;
}
