#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findShortestSubarray(vector<int>& nums) {
    unordered_map<int, int> left, right, count;
    int maxDegree = 0;

    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        if (left.find(num) == left.end()) {
            left[num] = i;
        }
        right[num] = i;
        count[num]++;
        maxDegree = max(maxDegree, count[num]);
    }

    int minLength = nums.size();
    for (const auto& kvp : count) {
        if (kvp.second == maxDegree) {
            int num = kvp.first;
            minLength = min(minLength, right[num] - left[num] + 1);
        }
    }

    return minLength;
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    int shortestSubarrayLength = findShortestSubarray(nums);
    cout << "Smallest subarray length with the same degree: " << shortestSubarrayLength << endl;

    return 0;
}
