#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& candidates, int target, int start, vector<int>& path, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(path);
        return;
    }
    
    for (int i = start; i < candidates.size(); ++i) {
        if (target < candidates[i]) {
            continue;
        }
        
        path.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i, path, result);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> path;
    backtrack(candidates, target, 0, path, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    
    for (const vector<int>& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
