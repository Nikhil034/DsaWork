#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSeed(vector<int>& nums, int space) {
    sort(nums.begin(), nums.end());  // Sort the array in ascending order
    int maxTargetsDestroyed = 0;
    int minSeed = 0;

    for (int i = 0; i < nums.size(); i++) {
        int targetsDestroyed = i;  // Initialize targetsDestroyed with the number of elements to the left of nums[i]
        for (int j = i + 1; j < nums.size(); j++) {
            // Calculate the number of targets that can be destroyed using nums[i] as the seed
            int destroyed = (nums[j] - nums[i]) / space;
            targetsDestroyed += destroyed;
        }

        if (targetsDestroyed > maxTargetsDestroyed) {
            maxTargetsDestroyed = targetsDestroyed;
            minSeed = nums[i];
        }
    }

    return minSeed;
}

int main() {
    vector<int> nums = {9, 10, 11, 12, 13, 14};
    int space = 2;
    cout << minSeed(nums, space) << endl; // Output: 9

    return 0;
}
