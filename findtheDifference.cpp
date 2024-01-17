#include <iostream>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> charCount;

    // Count characters in string s
    for (char ch : s) {
        charCount[ch]++;
    }

    // Subtract characters in string t
    for (char ch : t) {
        charCount[ch]--;
        if (charCount[ch] < 0) {
            return ch;
        }
    }

    return '\0'; // In case of invalid input or no difference
}

int main() {
    // Example usage
    string s = "abcd";
    string t = "abcde";

    char result = findTheDifference(s, t);

    cout << "The added character is: " << result << endl;

    return 0;
}
