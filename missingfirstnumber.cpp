#include <iostream>
#include <vector>
#include <algorithm>

int firstMissingNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int missing = 1; // Initializing the first missing number

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == missing) {
            missing++;
        }
    }

    return missing;
}

int main() {
    std::vector<int> numbers = {3, 4, -1, 1, 6, 9}; // Example array
    int missing = firstMissingNumber(numbers);

    std::cout << "The first missing number is: " << missing << std::endl;

    return 0;
}
