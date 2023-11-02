#include <iostream>

int minOperations(int num1, int num2) {
    int operations = 0;

    while (num1 > 0 && num2 > 0) {
        if (num1 >= num2) {
            num1 -= num2;
        } else {
            num2 -= num1;
        }
        operations++;
    }

    return operations;
}

int main() {
    int num1, num2;
    std::cout << "Enter num1: ";
    std::cin >> num1;
    std::cout << "Enter num2: ";
    std::cin >> num2;

    int result = minOperations(num1, num2);
    std::cout << "Number of operations required: " << result << std::endl;

    return 0;
}
