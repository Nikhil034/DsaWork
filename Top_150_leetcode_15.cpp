#include <iostream>
#include <map>

namespace RomanNumerals {
    std::string intToRoman(int num) {
        std::map<int, std::string> romanMap{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };
        
        std::string roman = "";
        for (const auto &pair : romanMap) {
            while (num >= pair.first) {
                roman += pair.second;
                num -= pair.first;
            }
        }
        
        return roman;
    }
}

int main() {
    int num = 3546; // Your integer here
    std::string romanNumeral = RomanNumerals::intToRoman(num);
    
    std::cout << num << " in Roman numerals is: " << romanNumeral << std::endl;
    
    return 0;
}
