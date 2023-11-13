#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);

        if (i == currEnd) {
            ++jumps;
            currEnd = farthest;

            if (currEnd >= n - 1) {
                break;
            }
        }
    }

    return jumps;
}

int main() {
    // Example usage:
    vector<int> nums = {2, 3, 1, 1, 4};
    int result = jump(nums);

    cout << "Minimum number of jumps: " << result << endl;

    return 0;
}
