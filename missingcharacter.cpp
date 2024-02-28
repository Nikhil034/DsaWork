#include <iostream>
#include <unordered_map>

char findAddedLetter(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> count;
    
    // Count characters in string t
    for (char c : t)
        count[c]++;
    
    // Subtract counts of characters in string s
    for (char c : s)
        count[c]--;
    
    // Find the character with non-zero count
    for (const auto& pair : count) {
        if (pair.second > 0)
            return pair.first;
    }
    
    // If no character is added (unlikely scenario), return '\0' or handle accordingly
    return '\0';
}

int main() {
    std::string s = "abcd";
    std::string t = "abcde"; // Random shuffle of "abcd" with one more letter 'e' added
    
    char addedLetter = findAddedLetter(s, t);
    
    if (addedLetter != '\0')
        std::cout << "Added letter: " << addedLetter << std::endl;
    else
        std::cout << "No letter added." << std::endl;
    
    return 0;
}
