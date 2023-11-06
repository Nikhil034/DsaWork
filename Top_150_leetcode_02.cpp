#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0; // Counter for elements not equal to val

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3, 2, 4, 5, 2};
    int val = 2;

    int k = removeElement(nums, val);

    std::cout << "Updated array (first " << k << " elements): ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }

    return 0;
}
