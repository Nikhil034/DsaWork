#include <iostream>
#include <string>
#include <sstream>

std::string reverseWords(std::string s) {
    std::istringstream iss(s);
    std::string word;
    std::string reversedString;

    while (iss >> word) {
        if (!reversedString.empty()) {
            reversedString = word + " " + reversedString;
        } else {
            reversedString = word;
        }
    }

    return reversedString;
}

int main() {
    std::string s = "  Hello  World!  ";
    std::string result = reverseWords(s);
    std::cout << result << std::endl;  // Output: "World! Hello"
    return 0;
}
