#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

bool wordPattern(std::string pattern, std::string s) {
    std::unordered_map<char, std::string> charToString;
    std::unordered_map<std::string, char> stringToChar;
    std::istringstream iss(s);
    std::vector<std::string> words;

    // Splitting the string into words
    while (iss >> s) {
        words.push_back(s);
    }

    // Check if the pattern length matches the number of words
    if (pattern.size() != words.size()) {
        return false;
    }

    for (int i = 0; i < pattern.size(); ++i) {
        char c = pattern[i];
        std::string word = words[i];

        if (charToString.find(c) == charToString.end() && stringToChar.find(word) == stringToChar.end()) {
            charToString[c] = word;
            stringToChar[word] = c;
        } else {
            if (charToString[c] != word || stringToChar[word] != c) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string pattern = "abba";
    std::string s = "dog cat cat dog";

    if (wordPattern(pattern, s)) {
        std::cout << "Follows the same pattern." << std::endl;
    } else {
        std::cout << "Does not follow the same pattern." << std::endl;
    }

    return 0;
}
