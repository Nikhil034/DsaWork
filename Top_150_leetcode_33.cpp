#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Flags to mark which rows and columns need to be zeroed
    bool zeroFirstRow = false;
    bool zeroFirstCol = false;

    // Check if the first row needs to be zeroed
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            zeroFirstRow = true;
            break;
        }
    }

    // Check if the first column needs to be zeroed
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            zeroFirstCol = true;
            break;
        }
    }

    // Use the first row and first column as markers
    // Update corresponding rows and columns if zero is found
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set elements to zero based on markers in first row and column
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (zeroFirstRow) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (zeroFirstCol) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
}

// Function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    setZeroes(matrix);

    cout << "\nMatrix After Setting Zeroes:" << endl;
    printMatrix(matrix);

    return 0;
}
