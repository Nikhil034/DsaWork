#include <iostream>
#include <string>

int lengthOfLastWord(const std::string& s) {
    int length = 0;
    int i = s.length() - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Calculate the length of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}

int main() {
    std::string input = "Hello World"; // Your input string here
    int lastWordLength = lengthOfLastWord(input);
    
    std::cout << "Length of the last word: " << lastWordLength << std::endl;
    
    return 0;
}
