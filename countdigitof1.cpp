#include <iostream>

int countDigitOne(int n) {
    int count = 0;
    
    for (int i = 1; i <= n; ++i) {
        int num = i;
        while (num > 0) {
            if (num % 10 == 1) {
                ++count;
            }
            num /= 10;
        }
    }

    return count;
}

int main() {
    int n;
    std::cout << "Enter a non-negative integer (n): ";
    std::cin >> n;

    int result = countDigitOne(n);

    std::cout << "The total number of digit 1 appearing in all non-negative integers up to " << n << " is: " << result << std::endl;

    return 0;
}
