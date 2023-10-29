#include <iostream>
#include <string>

using namespace std;

string addStrings(string num1, string num2) {
    int carry = 0;
    string result = "";

    int i = num1.length() - 1;
    int j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int x = (i >= 0) ? num1[i] - '0' : 0;
        int y = (j >= 0) ? num2[j] - '0' : 0;

        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;

        result = to_string(sum) + result;

        i--;
        j--;
    }

    return result;
}

int main() {
    string num1 = "123";
    string num2 = "456";

    string sum = addStrings(num1, num2);

    cout << "Sum: " << sum << endl;

    return 0;
}
