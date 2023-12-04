#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> findRanges(std::vector<int>& nums) {
    std::vector<std::string> result;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int start = nums[i];
        while (i + 1 < n && nums[i + 1] - nums[i] == 1) {
            ++i;
        }
        int end = nums[i];
        if (start == end) {
            result.push_back(std::to_string(start));
        } else {
            result.push_back(std::to_string(start) + "->" + std::to_string(end));
        }
    }
    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};
    std::vector<std::string> ranges = findRanges(nums);

    // Output the ranges
    for (const std::string& range : ranges) {
        std::cout << range << " ";
    }
    std::cout << std::endl;

    return 0;
}
