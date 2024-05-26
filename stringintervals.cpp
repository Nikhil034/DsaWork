#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int m = s1.length();
    int n = s2.length();
    int o = s3.length();

    if (m + n != o) {
        return false;
    }

    // Create a 2D array dp with (m + 1) x (n + 1) size and initialize it with false
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Initialize base cases
    dp[0][0] = true;

    for (int i = 1; i <= m; ++i) {
        dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    }

    for (int j = 1; j <= n; ++j) {
        dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
    }

    // Fill the dp table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    if (isInterleave(s1, s2, s3)) {
        cout << "s3 is an interleaving of s1 and s2" << endl;
    } else {
        cout << "s3 is not an interleaving of s1 and s2" << endl;
    }

    return 0;
}
