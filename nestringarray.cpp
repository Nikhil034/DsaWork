#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    int maxLength = 0;
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) // If num is already in a set, skip it
            continue;

        int current = num;
        int length = 0;

        while (seen.find(current) == seen.end()) {
            seen.insert(current);
            current = nums[current];
            length++;
        }

        maxLength = max(maxLength, length);
    }

    return maxLength;
}

int main() {
    // Example usage:
    vector<int> nums = {5, 4, 0, 3, 1, 6, 2};
    int result = longestConsecutive(nums);
    cout << "Longest length of a set s[k]: " << result << endl;
    return 0;
}
