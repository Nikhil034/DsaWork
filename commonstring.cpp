#include <vector>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

vector<string> findCommonLeastIndexSum(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> indexSumMap; // Map to store index sum for each common string
    int minIndexSum = INT_MAX;

    // Iterate through list1 and store index sum of each string in map
    for (int i = 0; i < list1.size(); ++i) {
        indexSumMap[list1[i]] = i;
    }

    vector<string> result;

    // Iterate through list2 and check for common strings
    for (int j = 0; j < list2.size(); ++j) {
        if (indexSumMap.find(list2[j]) != indexSumMap.end()) { // Found common string
            int indexSum = j + indexSumMap[list2[j]]; // Calculate index sum
            if (indexSum < minIndexSum) { // Check if it's the minimum index sum
                minIndexSum = indexSum;
                result.clear();
                result.push_back(list2[j]);
            } else if (indexSum == minIndexSum) { // If there are multiple common strings with same index sum
                result.push_back(list2[j]);
            }
        }
    }

    return result;
}
