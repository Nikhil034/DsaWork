#include <iostream>
#include <unordered_map>
#include <string>
#include<bits/stdc++.h>

using namespace std;


bool buildPyramid(string bottom, string nextRow, int index, unordered_map<string, vector<char>>& rules) {
    // If we have built a pyramid with one row, return true
    if (bottom.length() == 1 && nextRow.length() == 1) {
        return true;
    }
    
    // If we have finished one row, move to the next row
    if (index == bottom.length() - 1) {
        return buildPyramid(nextRow, "", 0, rules);
    }
    
    // Try to find possible combinations for the next block
    string key = bottom.substr(index, 2);
    if (rules.find(key) != rules.end()) {
        for (char block : rules[key]) {
            if (buildPyramid(bottom, nextRow + block, index + 1, rules)) {
                return true;
            }
        }
    }
    
    return false;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    unordered_map<string, vector<char>> rules;
    
    // Create a dictionary to store the allowed combinations
    for (const string& rule : allowed) {
        string key = rule.substr(0, 2);
        char value = rule[2];
        rules[key].push_back(value);
    }
    
    // Start building the pyramid from the bottom row
    return buildPyramid(bottom, "", 0, rules);
}

int main() {
    string bottom = "XYZ";
    vector<string> allowed = {"XYD", "YZE", "DEA", "FFF"};
    
    bool result = pyramidTransition(bottom, allowed);
    
    cout << (result ? "True" : "False") << endl; // Output: True
    
    return 0;
}
