#include <iostream>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // To handle cases where k is larger than the array size

    std::vector<int> rotated(n);

    // Copy the last k elements to the beginning of the rotated array
    for (int i = 0; i < k; ++i) {
        rotated[i] = nums[n - k + i];
    }

    // Copy the remaining elements to the rotated array
    for (int i = 0; i < n - k; ++i) {
        rotated[k + i] = nums[i];
    }

    // Copy the rotated array back to the original array
    nums = rotated;
}

int main() {
    // Example usage
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate(nums, k);

    // Display the rotated array
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
