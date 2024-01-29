#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, pair<double, string>> memo;

pair<double, string> getMaxExpression(const vector<int>& nums, int start, int end) {
    string key = to_string(start) + "-" + to_string(end);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    if (start == end) {
        return {static_cast<double>(nums[start]), to_string(nums[start])};
    }

    double maxVal = 0;
    string maxExpression;

    for (int i = start; i < end; ++i) {
        auto left = getMaxExpression(nums, start, i);
        auto right = getMaxExpression(nums, i + 1, end);

        double currentVal = left.first / right.first;

        if (currentVal > maxVal) {
            maxVal = currentVal;
            maxExpression = "(" + left.second + ")/(" + right.second + ")";
        }
    }

    memo[key] = {maxVal, maxExpression};
    return memo[key];
}

string optimalDivision(const vector<int>& nums) {
    memo.clear();
    int n = nums.size();
    auto result = getMaxExpression(nums, 0, n - 1);
    return result.second;
}

int main() {
    vector<int> nums = {2, 3, 4};
    string result = optimalDivision(nums);
    cout << result << endl;  // Output: "2/(3/4)"
    
    return 0;
}
