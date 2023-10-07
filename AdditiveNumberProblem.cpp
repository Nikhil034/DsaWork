#include <iostream>
#include <string>

using namespace std;

bool isAdditiveNumber(string num) {
    int n = num.length();
    
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string num1 = num.substr(0, i);
            string num2 = num.substr(i, j - i);
            
            // Check if leading zeros are present in num1 or num2
            if ((num1.length() > 1 && num1[0] == '0') || (num2.length() > 1 && num2[0] == '0'))
                continue;
            
            long long a = stoll(num1);
            long long b = stoll(num2);
            
            string expected = to_string(a + b);
            
            // Extract the remaining part of the string
            string remaining = num.substr(j);
            
            // If the expected sum is a prefix of the remaining string
            if (remaining.find(expected) == 0) {
                // If there are no remaining characters, it's an additive number
                if (remaining == expected || isAdditiveNumber(num2 + expected + remaining))
                    return true;
            }
        }
    }
    
    return false;
}

int main() {
    string num = "112358";
    if (isAdditiveNumber(num))
        cout << "The string forms an additive sequence." << endl;
    else
        cout << "The string does not form an additive sequence." << endl;
    
    return 0;
}
