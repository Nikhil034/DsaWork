#include <iostream>
#include <vector>

int rob(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    std::vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
        // Decide whether to rob the current house or skip it
        dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    return dp[n - 1];
}

int main() {
    std::vector<int> nums = {2, 7, 9, 3, 1}; // Change this array to represent the amount of money in each house
    int maxAmount = rob(nums);
    std::cout << "Maximum amount of money that can be robbed: " << maxAmount << std::endl;
    return 0;
}
