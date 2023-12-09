#include <iostream>
#include <vector>
#include <stack>
#include <string>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> numbers;

    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = numbers.top();
            numbers.pop();
            int operand1 = numbers.top();
            numbers.pop();

            if (token == "+") {
                numbers.push(operand1 + operand2);
            } else if (token == "-") {
                numbers.push(operand1 - operand2);
            } else if (token == "*") {
                numbers.push(operand1 * operand2);
            } else if (token == "/") {
                numbers.push(operand1 / operand2);
            }
        } else {
            numbers.push(std::stoi(token));
        }
    }

    return numbers.top();
}

int main() {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << "Result: " << evalRPN(tokens) << std::endl;
    return 0;
}
