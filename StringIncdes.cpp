#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sortString(string s) {
    // Create an array to store character frequencies
    vector<int> freq(26, 0);
    
    // Count the frequency of each character in the input string
    for (char ch : s) {
        freq[ch - 'a']++;
    }
    
    // Initialize the result string and flag for increasing phase
    string result = "";
    bool increasing = true;
    
    // Continue until all characters have been used
    while (result.length() < s.length()) {
        if (increasing) {
            // Append characters in increasing order
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    result += 'a' + i;
                    freq[i]--;
                }
            }
        } else {
            // Append characters in decreasing order
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    result += 'a' + i;
                    freq[i]--;
                }
            }
        }
        
        // Toggle the flag
        increasing = !increasing;
    }
    
    return result;
}

int main() {
    string s = "aaaabbbbcccc";
    
    string result = sortString(s);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
