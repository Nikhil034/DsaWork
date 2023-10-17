#include <iostream>
#include <vector>

int firstMissingPositive(std::vector<int>& nums) {
    int n = nums.size();

    // Cyclic Sort: Place each positive integer in its correct position
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            std::swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first missing positive integer
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }

    // If all positive integers from 1 to n are present, return n + 1
    return n + 1;
}

int main() {
    std::vector<int> nums = {3, 4, -1, 1};
    int result = firstMissingPositive(nums);
    std::cout << "First Missing Positive: " << result << std::endl;
    return 0;
}
