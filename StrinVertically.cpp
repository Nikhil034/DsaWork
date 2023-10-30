#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>

using namespace std;

vector<string> printVertically(string s) {
    vector<string> words; // To store individual words
    vector<string> result; // To store the vertically aligned words
    istringstream iss(s);
    string word;
    int maxLen = 0; // Maximum word length

    // Tokenize the input string to extract words and find the maximum length
    while (iss >> word) {
        words.push_back(word);
        maxLen = max(maxLen, static_cast<int>(word.length()));
    }

    int numWords = words.size();

    // Initialize the result with spaces
    for (int i = 0; i < maxLen; ++i) {
        result.push_back("");
    }

    // Place each word in the appropriate column
    for (int i = 0; i < numWords; ++i) {
        for (int j = 0; j < maxLen; ++j) {
            if (j < words[i].length()) {
                result[j] += words[i][j];
            } else {
                result[j] += ' '; // Add spaces for shorter words
            }
        }
    }

    // Remove trailing spaces and return the result
    for (int i = 0; i < maxLen; ++i) {
        while (!result[i].empty() && result[i].back() == ' ') {
            result[i].pop_back();
        }
    }

    return result;
}

int main() {
    string s = "HOW ARE YOU";
    vector<string> verticalWords = printVertically(s);

    cout << "Vertically aligned words:" << endl;
    for (const string& word : verticalWords) {
        cout << word << endl;
    }

    return 0;
}
