#include <iostream>

int divide(int dividend, int divisor) {
    if (dividend == 0) return 0; // Handle division by zero

    bool isNegative = (dividend < 0) ^ (divisor < 0); // Check if the result should be negative

    long long ldividend = std::abs(static_cast<long long>(dividend));
    long long ldivisor = std::abs(static_cast<long long>(divisor));

    int result = 0;
    while (ldividend >= ldivisor) {
        ldividend -= ldivisor;
        result++;
    }

    if (isNegative) result = -result;

    return result;
}

int main() {
    int dividend = 7;
    int divisor = -3;

    int result = divide(dividend, divisor);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
