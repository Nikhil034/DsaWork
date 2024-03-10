#include <vector>
#include <algorithm>

int thirdMax(std::vector<int>& nums) {
    // Sort the array in descending order
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    int distinctCount = 1; // Count of distinct maximum numbers
    int prevMax = nums[0]; // Initialize with the maximum number
    int thirdMax = nums[0]; // Initialize thirdMax with maximum number

    // Iterate through the sorted array
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] < prevMax) {
            // If the current number is less than the previous maximum,
            // update the previous maximum and increment distinctCount
            prevMax = nums[i];
            ++distinctCount;
        }
        if (distinctCount == 3) {
            // If we have found the third distinct maximum number,
            // update thirdMax and break out of the loop
            thirdMax = nums[i];
            break;
        }
    }

    return distinctCount >= 3 ? thirdMax : nums[0]; // Return thirdMax if exists, else return the maximum number
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int result = thirdMax(nums);
    std::cout << "Third distinct maximum: " << result << std::endl;
    return 0;
}
