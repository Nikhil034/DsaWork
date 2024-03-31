#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int total_sum = 0;
    int set_sum = 0;
    unordered_set<int> num_set;

    // Calculate total sum and sum of unique elements
    for(int num : nums) {
        total_sum += num;
        if(num_set.find(num) == num_set.end()) {
            num_set.insert(num);
            set_sum += num;
        }
    }

    // Duplicate number is the difference between total sum and set sum
    int duplicate_num = total_sum - set_sum;
    
    // Missing number can be calculated using the sum formula for 1 to n
    int missing_num = duplicate_num + (n * (n + 1)) / 2 - total_sum;
    
    return {duplicate_num, missing_num};
}

int main() {
    vector<int> nums = {1, 2, 2, 4};
    vector<int> result = findErrorNums(nums);
    cout << "Duplicate Number: " << result[0] << endl;
    cout << "Missing Number: " << result[1] << endl;
    return 0;
}
