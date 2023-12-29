#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    vector<int> result = {-1, -1};

    // Finding the leftmost index
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (left < nums.size() && nums[left] == target) {
        result[0] = left;
    } else {
        return result;
    }

    // Finding the rightmost index
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    result[1] = right;

    return result;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);

    cout << "Starting position: " << result[0] << endl;
    cout << "Ending position: " << result[1] << endl;

    return 0;
}
