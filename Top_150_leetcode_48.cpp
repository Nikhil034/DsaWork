#include <iostream>
#include <stack>
#include <cctype>

int calculate(std::string s) {
    std::stack<int> nums;
    int operand = 0;
    int result = 0;
    int sign = 1; // 1 represents positive, -1 represents negative

    for (char &c : s) {
        if (isdigit(c)) {
            operand = operand * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * operand;
            operand = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * operand;
            operand = 0;
            sign = -1;
        } else if (c == '(') {
            nums.push(result);
            nums.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * operand;
            result *= nums.top(); // apply the sign before the parenthesis
            nums.pop();
            result += nums.top(); // add the result calculated within the parenthesis
            nums.pop();
            operand = 0;
        }
    }

    return result + sign * operand;
}

int main() {
    std::string expression = "(1+(4+5+2)-3)+(6+8)";
    int result = calculate(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
