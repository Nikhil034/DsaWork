#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move the left pointer until it points to an alphanumeric character
        while (left < right && !isalnum(s[left])) {
            ++left;
        }
        
        // Move the right pointer until it points to an alphanumeric character
        while (left < right && !isalnum(s[right])) {
            --right;
        }

        // Convert characters to lowercase for comparison
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        ++left;
        --right;
    }

    return true;
}

int main() {
    string input = "A man, a plan, a canal, Panama";
    bool result = isPalindrome(input);

    if (result) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
