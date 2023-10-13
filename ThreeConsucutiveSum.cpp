#include <iostream>
using namespace std;

int* ReturnThreeConsecutive(int n) {
    int* arr = new int[3];  // Dynamically allocate an array

    if (n % 3 != 0) {
        arr[0] = arr[1] = arr[2] = 0;
    } else {
        int x = n / 3;
        arr[0] = x - 1;
        arr[1] = x;
        arr[2] = x + 1;
    }

    return arr;
}

int main() {
    int n;

    cout << "Enter your value: ";
    cin >> n;

    int* result = ReturnThreeConsecutive(n);

    cout << "Result: " << result[0] << " " << result[1] << " " << result[2] << endl;

    delete[] result;  // Remember to deallocate the dynamically allocated array

    return 0;
}
