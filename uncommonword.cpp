#include <iostream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> uncommonWords(string s1, string s2) {
    // Function to split a string into words
    vector<string> splitWords(const string &s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }

    // Count the frequency of words in both sentences
    unordered_map<string, int> freq;
    for (const string& word : splitWords(s1)) {
        freq[word]++;
    }
    for (const string& word : splitWords(s2)) {
        freq[word]++;
    }

    // Identify uncommon words
    vector<string> uncommon;
    for (const auto& pair : freq) {
        if (pair.second == 1) {
            uncommon.push_back(pair.first);
        }
    }

    return uncommon;
}

int main() {
    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> result = uncommonWords(s1, s2);

    cout << "Uncommon words: ";
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
