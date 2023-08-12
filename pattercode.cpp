#include <iostream>
using namespace std;

int main() {
    int arr[5][5];

    // Input the matrix values
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "Enter a value: ";
            cin >> arr[i][j];
        }
    }

    cout << "-----------Matrix Array is-------------\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // Arrays to store row and column flags
    bool rowHasZero[5] = {false};
    bool colHasZero[5] = {false};

    // Find rows and columns with zeros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == 0) {
                rowHasZero[i] = true;
                colHasZero[j] = true;
            }
        }
    }

    // Set rows and columns to zero if they have zeros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (rowHasZero[i] || colHasZero[j]) {
                arr[i][j] = 0;
            }
        }
    }

    cout << "-----------Matrix After Modification-------------\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
