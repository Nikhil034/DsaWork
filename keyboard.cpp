#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> findWords(const vector<string>& words) {
    // Define rows of the American keyboard
    unordered_set<char> row1{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    unordered_set<char> row2{'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    unordered_set<char> row3{'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    vector<string> result;

    for (const string& word : words) {
        bool sameRow = true;
        unordered_set<char> row;
        // Determine the row of the first character
        if (row1.count(tolower(word[0]))) row = row1;
        else if (row2.count(tolower(word[0]))) row = row2;
        else row = row3;

        // Check if all characters in the word belong to the same row
        for (char c : word) {
            if (!row.count(tolower(c))) {
                sameRow = false;
                break;
            }
        }

        if (sameRow) result.push_back(word);
    }

    return result;
}

int main() {
    vector<string> words = {"hello", "alaska", "dad", "peace"};
    vector<string> validWords = findWords(words);

    cout << "Words that can be typed using letters of the alphabet on only one row of the American keyboard:\n";
    for (const string& word : validWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
