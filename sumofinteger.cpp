#include <iostream>

int getSum(int a, int b) {
    while (b != 0) {
        // Carry contains common set bits of a and b
        int carry = a & b;

        // Sum of bits of a and b where at least one of the bits is not set
        a = a ^ b;

        // Carry is shifted by one so that adding it to a gives the required sum
        b = carry << 1;
    }

    return a;
}

int main() {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    int result = getSum(a, b);

    std::cout << "Sum is: " << result << std::endl;

    return 0;
}
