#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int minDeletions(string s, int target) {
    unordered_map<char, int> freq;
    int left = 0;
    int minLen = INT_MAX;
    int distinctCount = 0;

    for (int right = 0; right < s.length(); ++right) {
        if (freq[s[right]] == 0) {
            distinctCount++;
        }
        freq[s[right]]++;

        while (distinctCount > target) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) {
                distinctCount--;
            }
            left++;
        }

        if (distinctCount == target) {
            minLen = min(minLen, right - left + 1);
        }
    }

    return (minLen == INT_MAX) ? -1 : s.length() - minLen;
}

int main() {
    string s = "abaac";
    int target = 2;
    int result = minDeletions(s, target);
    cout << "Minimum deletions needed: " << result << endl;
    return 0;
}
