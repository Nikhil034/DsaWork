#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(const std::string& word) {
    // Helper function to check if a word is a palindrome
    int left = 0;
    int right = word.length() - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

std::vector<std::vector<int>> palindromePairs(const std::vector<std::string>& words) {
    std::vector<std::vector<int>> result;

    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i != j) {
                std::string combinedWord = words[i] + words[j];
                if (isPalindrome(combinedWord)) {
                    result.push_back({i, j});
                }
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::string> words = {"abcd", "dcba", "lls", "s", "sssll"};
    std::vector<std::vector<int>> palindromePairsResult = palindromePairs(words);

    for (const std::vector<int>& pair : palindromePairsResult) {
        std::cout << "[" << pair[0] << ", " << pair[1] << "]" << std::endl;
    }

    return 0;
}
