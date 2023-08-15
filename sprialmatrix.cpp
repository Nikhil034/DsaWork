#include <iostream>
using namespace std;

void printSpiralMatrix(int rows, int cols) {
    int matrix[rows][cols];
    
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int num = 1;
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;
        
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }
    
    // Print the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    
    cout << "Spiral Matrix:" << endl;
    printSpiralMatrix(rows, cols);
    
    return 0;
}
