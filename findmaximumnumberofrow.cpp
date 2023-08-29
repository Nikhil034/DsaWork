#include<iostream>
#include<vector>
using namespace std;

int main() {
    int arr[4][4], r, c, maxRow = -1, maxCount = -1;

    for (r = 0; r < 4; r++) {
        int count = 0; // Initialize count for each row
        for (c = 0; c < 4; c++) {
            cout << "Enter a value=";
            cin >> arr[r][c];
            count += arr[r][c]; // Count 1s while taking input
        }
        if (count > maxCount) {
            maxCount = count;
            maxRow = r;
        }
    }

    cout << "ROW WITH MAXIMUM 1S=" << maxRow;

    return 0;
}
