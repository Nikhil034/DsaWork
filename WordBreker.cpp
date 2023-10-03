#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.length();
    // dp[i] represents whether the substring s[0...i-1] can be segmented into words in the wordDict.
    vector<bool> dp(n + 1, false);
    dp[0] = true; // An empty string can always be segmented.

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            // Check if s[0...j-1] can be segmented and s[j...i-1] is in the wordDict.
            if (dp[j] && wordDict.count(s.substr(j, i - j)) > 0) {
                dp[i] = true;
                break; // If we found a valid word, no need to continue checking.
            }
        }
    }

    return dp[n];
}

int main() {
    string s = "leetcode";
    unordered_set<string> wordDict = {"leet", "code"};

    if (wordBreak(s, wordDict)) {
        cout << "The string can be segmented into words." << endl;
    } else {
        cout << "The string cannot be segmented into words." << endl;
    }

    return 0;
}
