#include <string>
#include <cctype>

bool isRightCapitalUsage(const std::string& word) {
    int n = word.size();
    if (n <= 1) // Single letter or empty string
        return true;
    
    // Case 1: All letters in this word are capitals
    bool allCapitals = true;
    for (char c : word) {
        if (!std::isupper(c)) {
            allCapitals = false;
            break;
        }
    }
    if (allCapitals)
        return true;
    
    // Case 2: All letters in this word are not capitals
    bool allLowercase = true;
    for (char c : word) {
        if (!std::islower(c)) {
            allLowercase = false;
            break;
        }
    }
    if (allLowercase)
        return true;
    
    // Case 3: Only the first letter in this word is capital
    if (std::isupper(word[0])) {
        for (int i = 1; i < n; ++i) {
            if (std::isupper(word[i]))
                return false;
        }
        return true;
    }
    
    return false;
}

// Example usage:
#include <iostream>
int main() {
    std::string word1 = "USA";
    std::string word2 = "leetcode";
    std::string word3 = "Google";
    
    std::cout << std::boolalpha;
    std::cout << "Word 1: " << isRightCapitalUsage(word1) << std::endl;
    std::cout << "Word 2: " << isRightCapitalUsage(word2) << std::endl;
    std::cout << "Word 3: " << isRightCapitalUsage(word3) << std::endl;
    
    return 0;
}
