#include <iostream>
#include <vector>
#include <algorithm>

int maximumGap(std::vector<int>& nums) {
    if (nums.size() < 2) {
        return 0;
    }

    std::sort(nums.begin(), nums.end());

    int maxGap = 0;
    for (int i = 1; i < nums.size(); ++i) {
        maxGap = std::max(maxGap, nums[i] - nums[i - 1]);
    }

    return maxGap;
}

int main() {
    std::vector<int> nums = {3, 6, 9, 1};
    std::cout << "Maximum gap: " << maximumGap(nums) << std::endl;

    return 0;
}
