#include <iostream>
#include <vector>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int i = 0;

    while (i < words.size()) {
        int j = i + 1, lineLength = words[i].length();

        while (j < words.size() && lineLength + words[j].length() + (j - i) <= maxWidth) {
            lineLength += words[j].length();
            ++j;
        }

        int diff = maxWidth - lineLength;
        int numWords = j - i;
        int numGaps = numWords - 1;

        string line = words[i];

        // If it's not the last line and there's more than one word
        if (j != words.size() && numWords > 1) {
            int spaces = diff / numGaps;
            int extraSpaces = diff % numGaps;

            for (int k = i + 1; k < j; ++k) {
                line += string(spaces, ' ');

                // Distributing extra spaces
                if (extraSpaces > 0) {
                    line += ' ';
                    extraSpaces--;
                }

                line += words[k];
            }
        } else { // Last line or line with one word
            for (int k = i + 1; k < j; ++k) {
                line += ' ';
                line += words[k];
            }

            line += string(maxWidth - line.length(), ' ');
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    vector<string> justifiedText = fullJustify(words, maxWidth);

    for (const auto& line : justifiedText) {
        cout << line << endl;
    }

    return 0;
}
