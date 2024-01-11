#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') result.push_back(l + r);
                        else if (c == '-') result.push_back(l - r);
                        else if (c == '*') result.push_back(l * r);
                    }
                }
            }
        }
        
        // If the input contains only a number
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    string input = "2-1-1";
    vector<int> result = solution.diffWaysToCompute(input);
    
    cout << "Results: ";
    for (int res : result) {
        cout << res << " ";
    }
    
    return 0;
}
