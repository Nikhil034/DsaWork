#include <vector>
#include <queue>
#include<iostream>

using namespace std;

int countLessOrEqual(const vector<vector<int>>& matrix, int target) {
    int count = 0;
    int n = matrix.size();
    int row = n - 1;
    int col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= target) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(const vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessOrEqual(matrix, mid);

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;

    int result = kthSmallest(matrix, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
