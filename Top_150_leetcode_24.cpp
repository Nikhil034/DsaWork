#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end()); // Sorting the array
    
    std::vector<std::vector<int>> result;
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates for the first element of the triplet
        }
        int left = i + 1, right = nums.size() - 1;
        
        while (left < right) {
            int total = nums[i] + nums[left] + nums[right];
            if (total < 0) {
                left++;
            } else if (total > 0) {
                right--;
            } else {
                result.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) {
                    left++; // Skip duplicates for the second element of the triplet
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--; // Skip duplicates for the third element of the triplet
                }
                left++;
                right--;
            }
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = threeSum(nums);
    
    // Printing the result
    for (const auto& triplet : result) {
        std::cout << "[";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
    
    return 0;
}
