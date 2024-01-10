#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n; // No need to process if the array has 2 or fewer elements

    int count = 2; // Start with the assumption that first two elements are allowed
    for (int i = 2; i < n; ++i) {
        if (nums[i] != nums[count - 2]) {
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

int main() {
    std::vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int k = removeDuplicates(nums);

    std::cout << "k: " << k << std::endl;
    std::cout << "Modified Array: ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
