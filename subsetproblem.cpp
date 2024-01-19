#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
    // Add the current subset to the result
    result.push_back(current);

    // Iterate through the remaining elements in the array
    for (int i = start; i < nums.size(); ++i) {
        // Skip duplicates to avoid duplicate subsets
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }

        // Include the current element in the subset
        current.push_back(nums[i]);

        // Recursively generate subsets starting from the next index
        backtrack(nums, i + 1, current, result);

        // Backtrack to remove the current element and explore other possibilities
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    // Sort the array to handle duplicates
    sort(nums.begin(), nums.end());

    // Result vector to store all subsets
    vector<vector<int>> result;

    // Current vector to store the current subset being formed
    vector<int> current;

    // Start backtracking from index 0
    backtrack(nums, 0, current, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};
    
    // Call the function to get all subsets
    vector<vector<int>> subsets = subsetsWithDup(nums);

    // Print the result
    cout << "Subsets:\n";
    for (const auto& subset : subsets) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
