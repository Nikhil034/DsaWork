#include <iostream>
#include <vector>

using namespace std;

int findSubstringInWraproundString(string s) {
    if (s.empty()) {
        return 0;
    }

    vector<int> maxLen(26, 0);  // To store the maximum length of substring ending with each character.
    int len = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
            len++;
        } else {
            len = 1;
        }

        int index = s[i] - 'a';
        maxLen[index] = max(maxLen[index], len);
    }

    int result = 0;
    for (int i = 0; i < 26; i++) {
        result += maxLen[i];
    }

    return result;
}

int main() {
    string s = "zab";
    int uniqueSubstrings = findSubstringInWraproundString(s);
    cout << "Number of unique substrings: " << uniqueSubstrings << endl;
    return 0;
}
