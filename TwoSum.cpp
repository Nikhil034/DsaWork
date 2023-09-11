#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i};
        }

        numToIndex[nums[i]] = i;
    }

    return {}; // Return an empty vector if no solution is found
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array:";

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices of the two numbers that add up to the target sum: " << result[0] << " " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
