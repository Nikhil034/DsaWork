#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    // Sort the pairs based on the second element of each pair
    sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = pairs.size();
    vector<int> dp(n, 1); // dp[i] represents the length of the longest chain ending at pairs[i]

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pairs[j][1] < pairs[i][0]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum length in dp
    int max_length = 0;
    for (int len : dp) {
        max_length = max(max_length, len);
    }

    return max_length;
}

int main() {
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << "Length of the longest chain: " << findLongestChain(pairs) << endl;
    return 0;
}
