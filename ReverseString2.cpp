#include <iostream>
using namespace std;

int main() {
    string str;
    int len;

    cout << "Enter your string: ";
    cin >> str;

    cout << "ORIGINAL STRING: " << str;

    len = str.length() - 1;
    int start = 0;

    while (start < len) {
        // Swap characters at start and len positions
        char temp = str[start];
        str[start] = str[len];
        str[len] = temp;
        start++;
        len--;
    }

    cout << "\nREVERSE STRING: " << str;

    return 0;
}
