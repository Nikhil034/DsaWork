#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            // The minimum element must be in the left half including mid
            right = mid;
        } else {
            // The minimum element must be in the right half excluding mid
            left = mid + 1;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> nums2 = {0, 1, 2, 4, 5, 6, 7};

    int min1 = findMin(nums1);
    int min2 = findMin(nums2);

    cout << "Minimum element in nums1: " << min1 << endl;
    cout << "Minimum element in nums2: " << min2 << endl;

    return 0;
}
