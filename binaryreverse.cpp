#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

int reverseBinary(const std::string& binaryStr) {
    std::string reversedBinaryStr = binaryStr;
    std::reverse(reversedBinaryStr.begin(), reversedBinaryStr.end());

    int reversedValue = 0;
    for (size_t i = 0; i < reversedBinaryStr.size(); ++i) {
        if (reversedBinaryStr[i] == '1') {
            reversedValue += static_cast<int>(std::pow(2, i));
        }
    }

    return reversedValue;
}

int main() {
    std::string binaryInput;
    std::cout << "Enter a binary number: ";
    std::cin >> binaryInput;

    // Check if the input consists only of 0s and 1s
    if (binaryInput.find_first_not_of("01") != std::string::npos) {
        std::cout << "Invalid binary input!" << std::endl;
        return 1;
    }

    int reversedValue = reverseBinary(binaryInput);
    std::cout << "Reversed value: " << reversedValue << std::endl;

    return 0;
}
