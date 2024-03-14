#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Custom comparator function to sort numbers in a way that forms the largest number
bool customCompare(const string& num1, const string& num2) {
    return (num1 + num2) > (num2 + num1);
}

string largestNumber(vector<int>& nums) {
    vector<string> nums_str;
    
    // Convert integers to strings
    for (int num : nums) {
        nums_str.push_back(to_string(num));
    }
    
    // Sort numbers using custom comparator
    sort(nums_str.begin(), nums_str.end(), customCompare);
    
    // Concatenate sorted numbers to form the largest number
    string result;
    for (const string& num_str : nums_str) {
        result += num_str;
    }
    
    // Handle edge case where the result is "0"
    if (result[0] == '0') {
        return "0";
    }
    
    return result;
}

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << "Largest Number: " << largestNumber(nums) << endl;
    return 0;
}
