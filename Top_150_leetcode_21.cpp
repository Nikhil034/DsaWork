#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int sIndex = 0;
    int tIndex = 0;

    while (sIndex < s.length() && tIndex < t.length()) {
        if (s[sIndex] == t[tIndex]) {
            // Move both pointers if the characters match
            sIndex++;
            tIndex++;
        } else {
            // Move only the pointer for string t
            tIndex++;
        }
    }

    // If all characters of s are matched, s is a subsequence of t
    return sIndex == s.length();
}

int main() {
    string s = "ace";
    string t = "abcde";

    if (isSubsequence(s, t)) {
        cout << "s is a subsequence of t." << endl;
    } else {
        cout << "s is not a subsequence of t." << endl;
    }

    return 0;
}
