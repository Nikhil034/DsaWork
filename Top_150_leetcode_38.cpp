#include <iostream>
#include <unordered_map>

bool isAnagram(const std::string& s, const std::string& t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, int> charCount;

    // Count occurrences of characters in string s
    for (char c : s) {
        charCount[c]++;
    }

    // Decrement count for characters in string t
    for (char c : t) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
            return false; // If character not found or count becomes negative
        }
        charCount[c]--;
    }

    return true;
}

int main() {
    std::string s = "listen";
    std::string t = "silent";

    if (isAnagram(s, t)) {
        std::cout << "They are anagrams!" << std::endl;
    } else {
        std::cout << "They are not anagrams." << std::endl;
    }

    return 0;
}
