#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
    int furthestReach = 0;

    for (int i = 0; i < nums.size(); ++i) {
        // If the current index is beyond the furthest reachable position, return false
        if (i > furthestReach) {
            return false;
        }

        // Update the furthest reachable position
        furthestReach = std::max(furthestReach, i + nums[i]);

        // If the furthest reachable position is beyond or at the last index, return true
        if (furthestReach >= nums.size() - 1) {
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage
    std::vector<int> nums1 = {2, 3, 1, 1, 4};
    std::vector<int> nums2 = {3, 2, 1, 0, 4};

    std::cout << std::boolalpha;  // to print bool values as true/false

    std::cout << "Can reach last index (nums1): " << canJump(nums1) << std::endl;
    std::cout << "Can reach last index (nums2): " << canJump(nums2) << std::endl;

    return 0;
}
