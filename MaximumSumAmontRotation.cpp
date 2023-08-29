#include <iostream>
using namespace std;

int main() {
    int arr[4] = {8, 3, 1, 2}, sum = 0;

    int size = sizeof(arr) / sizeof(arr[0]);
    int ele = 0, mul;

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout << "{8, 3, 1, 2}\n";
        }
        for (int k = 0; k < size; k++) {
            mul = arr[k] * k;
            cout << " " << arr[k] << " * " << k << " ";
            sum += mul;
            cout << "= " << sum << endl;
        }
        arr[size - 1] = arr[ele];
        arr[ele] = arr[ele + 1];
    }


    return 0;
}
