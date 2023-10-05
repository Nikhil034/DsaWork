#include <iostream>
#include <vector>

using namespace std;

int maximizeNumber(int num, int k) {
    string numStr = to_string(num);
    int n = numStr.length();
    
    // Create a 2D DP array to store maximum values
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    // Initialize DP array
    for (int i = 0; i < n; i++) {
        dp[i][i] = numStr[i] - '0'; // Single-digit number
    }
    
    // Fill in the DP array
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); // Initialize with maximum values
            
            for (int m = i; m < j; m++) {
                int product = dp[i][m] * dp[m + 1][j]; // Calculate product
                dp[i][j] = max(dp[i][j], product); // Update maximum
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    int num = 4321;
    int k = 2;
    
    int result = maximizeNumber(num, k);
    cout << "Maximum number after removing " << k << " digits: " << result << endl;
    
    return 0;
}
