#include <iostream>
using namespace std;

int main() {
    int nth, i, count = 0, ans = 0;
    cout << "Enter nth prime number: ";
    cin >> nth;

    for (i = 2; i < 1000005; i++) {
        bool isPrime = true;

        for (int j = 2; j<= i/2; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            count++;

            if (count == nth) {
                ans = i;
                break;
            }
        }
    }

    cout << nth << " prime number value is = " << ans;

    return 0;
}
