#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

vector<int> findCommonElements(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    unordered_map<int, int> count;
    unordered_set<int> result;

    for (int num : nums1) {
        count[num]++;
    }
    for (int num : nums2) {
        count[num]++;
    }
    for (int num : nums3) {
        count[num]++;
    }

    for (const auto& pair : count) {
        if (pair.second >= 2) {
            result.insert(pair.first);
        }
    }

    return vector<int>(result.begin(), result.end());
}

int main() {
    vector<int> nums1 = {1, 1, 3, 2};
    vector<int> nums2 = {2, 3};
    vector<int> nums3 = {3};

    vector<int> result = findCommonElements(nums1, nums2, nums3);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
