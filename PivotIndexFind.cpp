#include <iostream>
#include <vector>

int findPivotIndex(std::vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;

    for (int num : nums) {
        totalSum += num;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == (totalSum - leftSum - nums[i])) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = findPivotIndex(nums);
    if (result != -1) {
        std::cout << "The pivot index is: " << result << std::endl;
    } else {
        std::cout << "No pivot index found." << std::endl;
    }
    return 0;
}
