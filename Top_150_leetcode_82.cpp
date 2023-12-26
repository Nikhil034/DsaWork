#include <iostream>
#include <vector>

int findPeakElement(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            // Move right since a peak must exist on the right side
            left = mid + 1;
        } else {
            // Move left since a peak must exist on the left side or mid could be a peak
            right = mid;
        }
    }

    // At the end of the loop, left == right is the index of the peak
    return left;
}

int main() {
    std::vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    int peakIndex = findPeakElement(nums);
    std::cout << "A peak element is at index: " << peakIndex << std::endl;

    return 0;
}
