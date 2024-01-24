#include <iostream>
#include <vector>
#include <algorithm>

int minMoves2(std::vector<int>& nums) {
    int n = nums.size();
    
    // Sort the array to find the median
    std::sort(nums.begin(), nums.end());
    
    // Find the median
    int median = nums[n / 2];
    
    // Calculate the sum of absolute differences
    int moves = 0;
    for (int num : nums) {
        moves += std::abs(num - median);
    }
    
    return moves;
}

int main() {
    // Example usage
    std::vector<int> nums = {8, 2, 9,5,1};
    int result = minMoves2(nums);
    
    std::cout << "Minimum number of moves: " << result << std::endl;
    
    return 0;
}
