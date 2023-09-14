#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
        return ""; // If the input array is empty, there is no common prefix.
    }

    string prefix = strs[0]; // Start with the first string as the initial prefix.

    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            // Keep removing characters from the current prefix until it's a prefix of strs[i].
            prefix = prefix.substr(0, prefix.length() - 1);
            if (prefix.empty()) {
                return ""; // If the prefix becomes empty, there is no common prefix.
            }
        }
    }

    return prefix;
}

int main() {
    vector<string> input = {"flower", "flow", "flight"};
    string lcp = longestCommonPrefix(input);
    cout << "Longest Common Prefix: " << lcp << endl;
    return 0;
}
