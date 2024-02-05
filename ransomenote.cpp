#include <iostream>
#include <unordered_map>

bool canConstruct(string ransomNote, string magazine) {
    std::unordered_map<char, int> charCount;

    // Count occurrences of each character in magazine
    for (char ch : magazine) {
        charCount[ch]++;
    }

    // Check if ransomNote can be constructed
    for (char ch : ransomNote) {
        if (charCount.find(ch) == charCount.end() || charCount[ch] == 0) {
            return false; // Character not found or no more occurrences left
        }
        charCount[ch]--;
    }

    return true;
}

int main() {
    // Example usage:
    std::string ransomNote = "aabb";
    std::string magazine = "aabbc";
    
    if (canConstruct(ransomNote, magazine)) {
        std::cout << "Ransom note can be constructed." << std::endl;
    } else {
        std::cout << "Ransom note cannot be constructed." << std::endl;
    }

    return 0;
}
