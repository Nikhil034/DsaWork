#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void partitionHelper(const string& s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }
    
    for (int i = start; i < s.length(); ++i) {
        if (isPalindrome(s, start, i)) {
            current.push_back(s.substr(start, i - start + 1));
            partitionHelper(s, i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    return result;
}

// Example usage
int main() {
    string input = "aab";
    vector<vector<string>> partitions = partition(input);
    
    cout << "All possible palindrome partitions of '" << input << "':\n";
    for (const auto& partition : partitions) {
        cout << "[";
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}
