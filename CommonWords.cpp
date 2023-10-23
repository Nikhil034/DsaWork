#include <iostream>
#include <vector>
#include <unordered_map>

int countCommonWordsWithOneOccurrence(std::vector<std::string>& words1, std::vector<std::string>& words2) {
    std::unordered_map<std::string, int> wordCount1;
    std::unordered_map<std::string, int> wordCount2;

    // Count the occurrences of words in the first array
    for (const std::string& word : words1) {
        wordCount1[word]++;
    }

    // Count the occurrences of words in the second array
    for (const std::string& word : words2) {
        wordCount2[word]++;
    }

    int count = 0;

    // Iterate through the first array and count words that appear exactly once in both arrays
    for (const std::string& word : words1) {
        if (wordCount1[word] == 1 && wordCount2.find(word) != wordCount2.end() && wordCount2[word] == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    std::vector<std::string> words1 = {"apple", "banana", "cherry", "apple"};
    std::vector<std::string> words2 = {"banana", "cherry", "date", "date"};

    int result = countCommonWordsWithOneOccurrence(words1, words2);

    std::cout << "Number of common words with one occurrence: " << result << std::endl;

    return 0;
}
