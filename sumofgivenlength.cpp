#include <iostream>
#include <vector>

using namespace std;

vector<int> selectedElements;

bool findCombination(const vector<int>& nums, int targetSum, int currentIndex, int currentLength) {
    if (currentLength == 0) {
        return targetSum == 0;
    }

    if (currentIndex >= nums.size()) {
        return false;
    }

    // Include the current element in the combination
    selectedElements.push_back(nums[currentIndex]);
    if (findCombination(nums, targetSum - nums[currentIndex], currentIndex + 1, currentLength - 1)) {
        return true;
    }
    selectedElements.pop_back();  // Backtrack

    // Exclude the current element from the combination
    if (findCombination(nums, targetSum, currentIndex + 1, currentLength)) {
        return true;
    }

    return false;
}

int main() {
    vector<int> nums = {5, 8, 7, 1, 2, 1};
    int targetSum = 15;
    int desiredLength = 5;

    if (findCombination(nums, targetSum, 0, desiredLength)) {
        cout << "Combination with sum " << targetSum << " and length " << desiredLength << " is: ";
        for (int num : selectedElements) {
            cout << num << " ";
        }
        cout << endl;
    } else {
        cout << "No such combination found." << endl;
    }

    return 0;
}
