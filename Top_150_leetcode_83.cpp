#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    
    // Iterate from the least significant digit
    for (int i = n - 1; i >= 0; --i) {
        // Increment the current digit
        digits[i]++;
        
        // If the digit became 10 after increment, set it to 0 and carry 1 to the next digit
        if (digits[i] == 10) {
            digits[i] = 0;
        } else {
            // If the digit is less than 10, no need for further carry, return digits
            return digits;
        }
    }
    
    // If the loop completes, it means the entire number was 999...99 and needs to be changed to 1000...00
    digits[0] = 1; // Set the most significant digit to 1
    digits.push_back(0); // Add a new least significant digit with value 0
    
    return digits;
}

int main() {
    // Example usage
    std::vector<int> number = {9, 9, 9}; // Example input: [9, 9, 9]
    
    std::vector<int> result = plusOne(number);
    
    // Display the result
    std::cout << "Incremented number: ";
    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
