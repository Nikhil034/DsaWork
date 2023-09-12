#include<iostream>
using namespace std;

int main() {
    int n, rev = 0;
    cout << "Enter a value: ";
    cin >> n;

    int sign = (n < 0) ? -1 : 1; // Determine the sign of the number

    n = abs(n); // Make the number positive for reversal

    while (n > 0) {
        int rem = n % 10;
        rev = (rev * 10) + rem;
        n = n / 10;
    }

    rev *= sign; // Restore the sign

    cout << "\nREVERSE NUMBER: " << rev;

    return 0;
}
