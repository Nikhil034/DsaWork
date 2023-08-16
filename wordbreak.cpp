#include <iostream>
#include <unordered_set>
#include <vector>

bool wordBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
    int n = s.length();
    std::vector<bool> dp(n + 1, false); // dp[i] indicates if the substring s[0...i-1] can be segmented
    
    dp[0] = true; // An empty string can always be segmented
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && wordDict.find(s.substr(j, i - j)) != wordDict.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
}

int main() {
    std::string s = "leetcode";
    std::unordered_set<std::string> wordDict = {"leet", "code"};
    
    if (wordBreak(s, wordDict)) {
        std::cout << "The string can be segmented." << std::endl;
    } else {
        std::cout << "The string cannot be segmented." << std::endl;
    }
    
    return 0;
}
