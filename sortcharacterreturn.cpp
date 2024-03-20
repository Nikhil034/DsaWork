#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s = "tree";

    map<char, int> freq;

    // Count the frequency of characters
    for (char c : s) {
        freq[c]++;
    }

    // Custom comparison function to sort based on frequency first, and then alphabetically
    auto cmp = [&](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second; // Sort by frequency in descending order
        } else {
            return a.first < b.first; // If frequency is same, sort alphabetically
        }
    };

    // Convert map to vector of pairs
    vector<pair<char, int>> keyValueVector(freq.begin(), freq.end());

    // Sort the vector based on custom comparison function
    sort(keyValueVector.begin(), keyValueVector.end(), cmp);

    // Display the sorted keys and their values
    string ans = "";
    for (const auto& pair : keyValueVector) {
        for (int i = 0; i < pair.second; ++i) {
            ans += pair.first;
        }
    }

    cout << ans << endl; // Output the sorted string
    return 0;
}
