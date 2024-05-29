#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int longestSubstring(string s, int k) {
    int n = s.length();
    if (n == 0 || k > n) return 0;
    
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    
    int left = 0, right = 0, result = 0;
    
    while (right < n) {
        char c = s[right];
        if (freq[c] >= k) {
            right++;
        } else {
            result = max(result, longestSubstring(s.substr(left, right - left), k));
            while (left < right) {
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
            right++;
        }
    }
    
    if (left == 0) return n; // Entire string satisfies the condition
    return max(result, longestSubstring(s.substr(left, right - left), k));
}

int main() {
    string s = "aaabb";
    int k = 3;
    cout << longestSubstring(s, k) << endl; // Output: 3 (substring "aaa")
    return 0;
}
