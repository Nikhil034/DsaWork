#include <vector>
#include <unordered_map>
#include <cstdlib>

class Solution {
public:
    Solution(int n, std::vector<int>& blacklist) {
        N = n;
        B = blacklist.size();
        // Map blacklisted integers to their corresponding replacement in [N-B, N)
        std::unordered_map<int, int> replaceMap;
        std::vector<int> validRange;

        for (int i = N - B; i < N; ++i) {
            validRange.push_back(i);
        }

        for (int num : blacklist) {
            replaceMap[num] = -1; // Mark blacklisted integers as to be replaced

            if (!validRange.empty()) {
                replaceMap[num] = validRange.back();
                validRange.pop_back();
            }
        }

        for (int num : blacklist) {
            if (replaceMap[num] == -1) {
                replaceMap[num] = validRange.back();
                validRange.pop_back();
            }
        }

        replaceMap_ = replaceMap;
    }

    int pick() {
        int r = rand() % (N - B);
        return replaceMap_.count(r) ? replaceMap_[r] : r;
    }

private:
    int N; // Range [0, N-1]
    int B; // Number of blacklisted integers
    std::unordered_map<int, int> replaceMap_; // Map to replace blacklisted integers with valid ones
};

int main() {
    // Example usage:
    int n = 5;
    std::vector<int> blacklist = {1, 2};
    Solution solution(n, blacklist);

    for (int i = 0; i < 5; ++i) {
        int result = solution.pick();
        std::cout << "Random Integer: " << result << std::endl;
    }

    return 0;
}
