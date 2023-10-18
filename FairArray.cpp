#include <iostream>
#include <vector>

int countFairIndices(std::vector<int>& nums) {
    int count = 0;

    int evenSum = 0;
    int oddSum = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            evenSum += nums[i];
        } else {
            oddSum += nums[i];
        }
    }

    int currentEvenSum = 0;
    int currentOddSum = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (evenSum - currentEvenSum + currentOddSum == oddSum - currentOddSum + currentEvenSum) {
                count++;
            }
            currentEvenSum += nums[i];
        } else {
            if (evenSum - currentEvenSum + currentOddSum == oddSum - currentOddSum + currentEvenSum) {
                count++;
            }
            currentOddSum += nums[i];
        }
    }

    return count;
}

int main() {
    std::vector<int> nums = {2, 1, 6, 4};
    int result = countFairIndices(nums);
    std::cout << result << std::endl; // Output: 1
    return 0;
}
