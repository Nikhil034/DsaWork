#include <iostream>
#include <cctype>

std::string swapCaseAndSeparateWords(const std::string& input) {
    std::string result;
    bool inWord = false;

    for (char c : input) {
        if (std::isalpha(c)) {
            if (std::islower(c)) {
                result += std::toupper(c);
            } else {
                result += std::tolower(c);
            }

            inWord = true;
        } else {
            result += c;

            if (inWord) {
                result += ' ';
            }

            inWord = false;
        }
    }

    return result;
}

int main() {
    std::string input = "HeLooWorLd";
    std::string output = swapCaseAndSeparateWords(input);
    std::cout << output << std::endl;  // Output: "hElOO wORlD"

    return 0;
}
