#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    string result = "";
    stack<int> numStack;
    stack<std::string> strStack;
    int num = 0;

    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0'); // Handle multi-digit numbers
        } else if (isalpha(c)) {
            result += c; // Collect characters
        } else if (c == '[') {
            numStack.push(num);
            strStack.push(result);
            num = 0;
            result = "";
        } else if (c == ']') {
            int repeatCount = numStack.top();
            numStack.pop();
            string repeatedStr = result;
            result = strStack.top();
            strStack.pop();
            for (int i = 0; i < repeatCount; i++) {
                result += repeatedStr;
            }
        }
    }

    return result;
}

int main() {
    string s = "3[a]2[bc]";
    string result = decodeString(s);
    cout << result << endl; // Output: "aaabcbc"
    return 0;
}
