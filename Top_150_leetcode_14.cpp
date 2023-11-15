#include <iostream>
#include <unordered_map>

int romanToInt(std::string s) {
    std::unordered_map<char, int> romanVals = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;
    int prevVal = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        int currVal = romanVals[s[i]];
        if (currVal < prevVal) {
            result -= currVal;
        } else {
            result += currVal;
        }
        prevVal = currVal;
    }

    return result;
}

int main() {
    std::string romanNum = "MCMXCIV"; // Example Roman numeral
    int convertedInt = romanToInt(romanNum);
    std::cout << "The integer value of " << romanNum << " is: " << convertedInt << std::endl;

    return 0;
}
