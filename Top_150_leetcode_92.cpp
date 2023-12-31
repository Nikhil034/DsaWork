#include <iostream>
#include <vector>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    // Initializing the DP table with the same size as the grid
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // Fill the DP table starting from the top-left
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int i = 1; i < n; ++i) {
        dp[0][i] = dp[0][i - 1] + grid[0][i];
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the DP table by choosing the minimum path sum
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }

    // Return the minimum sum path from top-left to bottom-right
    return dp[m - 1][n - 1];
}

int main() {
    std::vector<std::vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int minSumPath = minPathSum(grid);
    std::cout << "The minimum sum path from top-left to bottom-right is: " << minSumPath << std::endl;

    return 0;
}
