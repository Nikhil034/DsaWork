#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    int k = 0; // Counter for unique elements

    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    std::vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4, 5};

    int k = removeDuplicates(nums);

    std::cout << "Updated array (first " << k << " elements): ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }

    return 0;
}
