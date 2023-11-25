#include <iostream>
#include <unordered_map>
#include<bits/stdc++.h>

std::string minWindowSubstring(std::string s, std::string t) {
    if (s.empty() || t.empty()) return "";

    std::unordered_map<char, int> targetFreq, windowFreq;
    for (char c : t) {
        targetFreq[c]++;
    }

    int required = targetFreq.size();
    int formed = 0;
    int left = 0, right = 0;
    int minLen = INT_MAX;
    int minLeft = 0, minRight = 0;

    while (right < s.length()) {
        char current = s[right];
        windowFreq[current]++;

        if (targetFreq.find(current) != targetFreq.end() && windowFreq[current] == targetFreq[current]) {
            formed++;
        }

        while (left <= right && formed == required) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minLeft = left;
                minRight = right;
            }

            char leftChar = s[left];
            windowFreq[leftChar]--;
            if (targetFreq.find(leftChar) != targetFreq.end() && windowFreq[leftChar] < targetFreq[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::cout << "Minimum window substring: " << minWindowSubstring(s, t) << std::endl;
    return 0;
}
