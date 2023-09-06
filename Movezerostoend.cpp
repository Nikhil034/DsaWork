#include<iostream>
using namespace std;

int main() {
    int arr[9] = {6, 0, 8, 2, 3, 0, 4, 0, 1};

    int nonZeroIndex = 0;

    // Move all non-zero elements to the front of the array
    for (int i = 0; i < 9; i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    // Fill the remaining elements with zeros
    for (int i = nonZeroIndex; i < 9; i++) {
        arr[i] = 0;
    }

    for (int m = 0; m < 9; m++) {
        cout << arr[m] << " ";
    }

    return 0;
}
