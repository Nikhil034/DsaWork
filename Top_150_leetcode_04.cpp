#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;

    // Phase 1: Find the potential majority candidate
    for (int i = 1; i < nums.size(); ++i) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            ++count;
        } else {
            --count;
        }
    }

    // Phase 2: Verify if the candidate is the majority element
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            ++count;
        }
    }

    // The majority element is guaranteed to exist, so no need to check if count > 0
    return candidate;
}

int main() {
    // Example usage
    std::vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int result = majorityElement(nums);
    std::cout << "The majority element is: " << result << std::endl;

    return 0;
}
