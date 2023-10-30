#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the mapping of digits to letters
vector<string> letters = {
    "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"
};

// Helper function to perform DFS and generate combinations
void generateCombinations(string digits, string current, int index, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    int digit = digits[index] - '2';  // Convert digit to an index (0-7)
    string digitLetters = letters[digit];

    for (char c : digitLetters) {
        generateCombinations(digits, current + c, index + 1, result);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;

    if (digits.empty()) {
        return result;
    }

    generateCombinations(digits, "", 0, result);

    return result;
}

int main() {
    string digits = "23"; // Example input
    vector<string> combinations = letterCombinations(digits);

    cout << "Letter combinations for " << digits << ":" << endl;
    for (string combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
