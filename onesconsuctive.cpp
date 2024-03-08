#include <vector>
#include <iostream>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;

    for (int num : nums) {
        if (num == 1) {
            currentConsecutiveOnes++;
            maxConsecutiveOnes = max(maxConsecutiveOnes, currentConsecutiveOnes);
        } else {
            currentConsecutiveOnes = 0;
        }
    }

    return maxConsecutiveOnes;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1};
    int maxConsecutiveOnes = findMaxConsecutiveOnes(nums);
    cout << "Maximum number of consecutive 1's: " << maxConsecutiveOnes << endl;
    return 0;
}
