#include <iostream>
#include <string>

using namespace std;

int minOperations(string s) {
    int moves = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ) {
        if (s[i] == 'O') {
            i++;
        } else {
            // We found an 'X', so we need to flip it and the next two characters.
            moves++;
            i += 3;
        }
    }
    
    return moves;
}

int main() {
    string s;
    cin >> s;
    int result = minOperations(s);
    cout << "Minimum moves to convert the string to valid: " << result << endl;
    return 0;
}
