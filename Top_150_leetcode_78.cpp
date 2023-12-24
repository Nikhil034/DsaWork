#include <iostream>
#include <vector>
#include <algorithm>

int kadane(std::vector<int>& nums) {
    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int maxSubarraySumCircular(std::vector<int>& nums) {
    int totalSum = 0;
    int maxSubArraySum = kadane(nums);

    if (maxSubArraySum < 0)
        return maxSubArraySum;

    for (int i = 0; i < nums.size(); ++i) {
        totalSum += nums[i];
        nums[i] = -nums[i];
    }

    int maxNegativeSubArraySum = kadane(nums);

    int maxCircularSubArraySum = totalSum + maxNegativeSubArraySum;

    return std::max(maxCircularSubArraySum, maxSubArraySum);
}

int main() {
    std::vector<int> nums = {3, -1, 2, -1};
    int maxSum = maxSubarraySumCircular(nums);
    std::cout << "Maximum sum of non-empty subarray in circular array: " << maxSum << std::endl;

    return 0;
}
