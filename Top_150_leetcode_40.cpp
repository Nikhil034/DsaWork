#include <unordered_map>
#include <vector>

bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> indexMap; // Map to store element -> index

    for (int i = 0; i < nums.size(); ++i) {
        if (indexMap.find(nums[i]) != indexMap.end() && i - indexMap[nums[i]] <= k) {
            return true; // Found a duplicate within distance k
        }
        indexMap[nums[i]] = i; // Update the index of the element
    }

    return false; // No such duplicate found within distance k
}
