#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    // Check if the endWord is not in the wordList, return 0
    if (wordList.find(endWord) == wordList.end()) {
        return 0;
    }

    queue<string> q;
    q.push(beginWord);

    int ladderLength = 1;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            string word = q.front();
            q.pop();

            // Try all possible transformations by changing one character
            for (int j = 0; j < word.length(); ++j) {
                char originalChar = word[j];

                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) {
                        continue; // Skip the same character
                    }

                    word[j] = c;

                    if (word == endWord) {
                        return ladderLength + 1; // Found the endWord
                    }

                    if (wordList.find(word) != wordList.end()) {
                        q.push(word);
                        wordList.erase(word); // Mark word as visited
                    }
                }

                word[j] = originalChar; // Restore the word
            }
        }

        ++ladderLength;
    }

    return 0; // No ladder found
}

int main() {
    string startWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int ladderLengthResult = ladderLength(startWord, endWord, wordList);

    if (ladderLengthResult > 0) {
        cout << "The shortest word ladder length is: " << ladderLengthResult << endl;
    } else {
        cout << "No word ladder found." << endl;
    }

    return 0;
}
