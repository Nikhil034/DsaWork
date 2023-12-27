#include <iostream>

int trailingZeroes(int n) {
    int count = 0;
    
    // Keep dividing by powers of 5 and count the factors of 5
    while (n >= 5) {
        count += n / 5;
        n /= 5;
    }
    
    return count;
}

int main() {
    // Example usage
    int n = 25; // Change n to any desired value
    
    int zeros = trailingZeroes(n);
    
    std::cout << "Number of trailing zeroes in " << n << "! is: " << zeros << std::endl;
    
    return 0;
}
