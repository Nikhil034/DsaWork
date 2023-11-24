#include <iostream>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    int maxLength = 0;
    std::unordered_map<char, int> charIndexMap;
    int startIndex = 0;

    for (int endIndex = 0; endIndex < s.length(); endIndex++) {
        if (charIndexMap.find(s[endIndex]) != charIndexMap.end()) {
            // Update the start index to the next index of the repeated character
            startIndex = std::max(startIndex, charIndexMap[s[endIndex]] + 1);
        }

        charIndexMap[s[endIndex]] = endIndex;
        maxLength = std::max(maxLength, endIndex - startIndex + 1);
    }

    return maxLength;
}

int main() {
    std::string inputString = "abcabcbb";
    int result = lengthOfLongestSubstring(inputString);
    
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    
    return 0;
}
