#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> result;
    if (s.empty() || words.empty()) return result;

    int wordSize = words[0].size();
    int totalWords = words.size();
    int totalLength = wordSize * totalWords;

    std::unordered_map<std::string, int> wordCount;
    for (const std::string& word : words) {
        wordCount[word]++;
    }

    for (int i = 0; i <= static_cast<int>(s.size()) - totalLength; ++i) {
        std::unordered_map<std::string, int> seenWords;
        int j = 0;
        while (j < totalWords) {
            std::string word = s.substr(i + j * wordSize, wordSize);
            if (wordCount.find(word) != wordCount.end()) {
                seenWords[word]++;
                if (seenWords[word] > wordCount[word]) {
                    break;
                }
            } else {
                break;
            }
            ++j;
        }
        if (j == totalWords) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    std::string s = "barfoothefoobarman";
    std::vector<std::string> words = {"foo", "bar"};

    std::vector<int> indices = findSubstring(s, words);
    std::cout << "Starting indices of concatenated substrings: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    return 0;
}
