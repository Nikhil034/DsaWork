#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    unordered_set<int> numSet(nums.begin(), nums.end());

    for (int i = 1; i <= nums.size(); ++i) {
        if (numSet.find(i) == numSet.end()) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> disappeared = findDisappearedNumbers(nums);
    
    cout << "The disappeared numbers are: ";
    for (int num : disappeared) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
