#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
    int n = s.length();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    std::string s = "leetcode";
    std::vector<std::string> wordDict = { "leet", "code" };

    if (wordBreak(s, wordDict)) {
        std::cout << "String can be segmented into words from the dictionary.\n";
    } else {
        std::cout << "String cannot be segmented into words from the dictionary.\n";
    }

    return 0;
}
