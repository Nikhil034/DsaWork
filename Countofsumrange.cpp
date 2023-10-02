#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int n = nums.size();
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    
    vector<long long> sortedPrefixSum(prefixSum);
    sort(sortedPrefixSum.begin(), sortedPrefixSum.end());
    
    int count = 0;
    for (int i = 0; i < n; ++i) {
        long long left = prefixSum[i] - upper;
        long long right = prefixSum[i] - lower;
        count += upperBound(sortedPrefixSum.begin(), sortedPrefixSum.end(), right) -
                 lowerBound(sortedPrefixSum.begin(), sortedPrefixSum.end(), left);
    }
    
    return count;
}

int main() {
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    
    int result = countRangeSum(nums, lower, upper);
    
    cout << "Count of subarrays with sums in the range [" << lower << ", " << upper << "] is: " << result << endl;
    
    return 0;
}
