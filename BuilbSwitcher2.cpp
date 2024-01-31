#include <iostream>
#include <cmath>

int bulbSwitch(int n) {
    return static_cast<int>(sqrt(n));
}

int main() {
    int n;
    std::cout << "Enter the number of bulbs (n): ";
    std::cin >> n;

    int result = bulbSwitch(n);

    std::cout << "The number of bulbs that are on after " << n << " rounds is: " << result << std::endl;

    return 0;
}
