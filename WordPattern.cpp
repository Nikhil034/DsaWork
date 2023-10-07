#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> charToWord;
    unordered_map<string, char> wordToChar;
    int n = pattern.size();
    int i = 0; // Index for the string

    for (char ch : pattern) {
        // Check if the character is already mapped to a word
        if (charToWord.find(ch) != charToWord.end()) {
            // If the mapping is incorrect, return false
            if (charToWord[ch] != s.substr(i, s.find(' ', i) - i))
                return false;
        } else {
            // Check if the word is already mapped to a character
            string word = s.substr(i, s.find(' ', i) - i);
            if (wordToChar.find(word) != wordToChar.end()) {
                // If the mapping is incorrect, return false
                if (wordToChar[word] != ch)
                    return false;
            } else {
                // Create new mappings
                charToWord[ch] = word;
                wordToChar[word] = ch;
            }
        }

        // Move the index to the next word in the string
        i = s.find(' ', i);
        if (i == string::npos)
            break;
        i++; // Skip the space
    }

    // If the pattern and string have different lengths, return false
    if (i != string::npos || n != pattern.size())
        return false;

    return true;
}

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";
    bool result = wordPattern(pattern, s);
    
    if (result)
        cout << "The string follows the pattern." << endl;
    else
        cout << "The string does not follow the pattern." << endl;

    return 0;
}
