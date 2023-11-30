#include <iostream>
#include <unordered_map>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> letterCount;

    // Count the occurrences of each character in the magazine
    for (char ch : magazine) {
        letterCount[ch]++;
    }

    // Check if the ransomNote can be constructed
    for (char ch : ransomNote) {
        if (letterCount[ch] > 0) {
            letterCount[ch]--;
        } else {
            return false; // Cannot construct the ransomNote
        }
    }

    return true; // Able to construct the ransomNote
}

int main() {
    std::string ransomNote = "aabb";
    std::string magazine = "aabbc";

    if (canConstruct(ransomNote, magazine)) {
        std::cout << "Ransom note can be constructed from magazine.\n";
    } else {
        std::cout << "Ransom note cannot be constructed from magazine.\n";
    }

    return 0;
}
