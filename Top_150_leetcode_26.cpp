#include <iostream>
#include <vector>
#include <limits>

int minSubArrayLen(int target, std::vector<int>& nums) {
    int minLength = std::numeric_limits<int>::max();
    int sum = 0;
    int left = 0;
    
    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];
        
        while (sum >= target) {
            minLength = std::min(minLength, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }
    
    return (minLength != std::numeric_limits<int>::max()) ? minLength : 0;
}

int main() {
    // Example usage
    std::vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int minLength = minSubArrayLen(target, nums);
    std::cout << "Minimal length of subarray: " << minLength << std::endl;

    return 0;
}
