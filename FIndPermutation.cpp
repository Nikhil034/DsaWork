#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, int index, vector<vector<int>>& result) {
    if (index == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        // Swap the current element with the element at the current index
        swap(nums[index], nums[i]);

        // Recursively generate permutations for the remaining elements
        generatePermutations(nums, index + 1, result);

        // Undo the swap to backtrack and try the next possibility
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

int main() {
    vector<int> array = {1, 2, 3};
    vector<vector<int>> permutations = permute(array);

    // Display the permutations
    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
