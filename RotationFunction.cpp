#include <vector>
#include <algorithm>

int maxRotateFunction(std::vector<int>& nums) { 
    int n = nums.size();
    int sum = 0;
    int rotationSum = 0;

    for (int i = 0; i < n; ++i) {
        sum += nums[i]; 7 9
        rotationSum += i * nums[i]; 
    }

    int maxSum = rotationSum;

    for (int i = 1; i < n; ++i) {
        rotationSum += sum - n * nums[n - i];
        maxSum = std::max(maxSum, rotationSum);
    }

    return maxSum;
}
