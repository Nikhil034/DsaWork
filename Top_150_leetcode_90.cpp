#include <iostream>
#include <vector>
#include <climits>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int j = 0; j < coins.size(); ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;

    int minCoins = coinChange(coins, amount);
    if (minCoins == -1) {
        std::cout << "Cannot make up the amount using given coins.\n";
    } else {
        std::cout << "Minimum number of coins needed: " << minCoins << "\n";
    }

    return 0;
}
