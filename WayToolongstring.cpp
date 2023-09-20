#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string abbreviateWord(const string& word) {
    int length = word.length();
    if (length > 10) {
        ostringstream oss;
        oss << word[0] << length - 2 << word[length - 1];
        return oss.str();
    }
    return word;
}

string abbreviateText(const string& input) {
    istringstream iss(input);
    vector<string> words;
    string word;

    while (iss >> word) {
        words.push_back(abbreviateWord(word));
    }

    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        oss << words[i];
        if (i < words.size() - 1) {
            oss << ' ';
        }
    }

    return oss.str();
}

int main() {
    string inputText;
    cout << "Enter a text: ";
    getline(cin, inputText);

    string abbreviatedText = abbreviateText(inputText);
    cout << "Abbreviated text: " << abbreviatedText << endl;

    return 0;
}
