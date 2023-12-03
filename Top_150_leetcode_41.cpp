#include <unordered_set>
#include <vector>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> numSet(nums.begin(), nums.end()); // Convert nums to a hash set for O(1) lookup
    int longest = 0;

    for (int num : nums) {
        if (numSet.find(num - 1) == numSet.end()) { // Check if the current number is the start of a sequence
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) { // Count consecutive elements
                currentNum++;
                currentStreak++;
            }

            longest = std::max(longest, currentStreak); // Update the longest streak
        }
    }

    return longest;
}
