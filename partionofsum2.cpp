#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSumEqual(vector<int>& nums, vector<bool>& chosen, int targetSum, int currentIndex, int currentSum, int k) {
    if (k == 1) {
        return true; // If one subset is formed, the rest of the numbers are automatically in the last subset.
    }
    
    if (currentSum == targetSum) {
        return isSubsetSumEqual(nums, chosen, targetSum, 0, 0, k - 1);
    }
    
    for (int i = currentIndex; i < nums.size(); ++i) {
        if (!chosen[i]) {
            chosen[i] = true;
            if (isSubsetSumEqual(nums, chosen, targetSum, i + 1, currentSum + nums[i], k)) {
                return true;
            }
            chosen[i] = false;
        }
    }
    
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    
    if (totalSum % k != 0) {
        return false; // If total sum is not divisible by k, equal partition is not possible.
    }
    
    int targetSum = totalSum / k;
    vector<bool> chosen(nums.size(), false); // To keep track of chosen elements
    
    return isSubsetSumEqual(nums, chosen, targetSum, 0, 0, k);
}

int main() {
    int n, k;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    cout << "Enter the value of k: ";
    cin >> k;
    
    if (canPartitionKSubsets(nums, k)) {
        cout << "The set can be partitioned into " << k << " equal sum subsets." << endl;
    } else {
        cout << "The set cannot be partitioned into " << k << " equal sum subsets." << endl;
    }
    
    return 0;
}
