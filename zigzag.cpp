#include <iostream>
#include <vector>

void printMatrixDiagonal(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Iterate over the upper half of the matrix diagonals
    for (int k = 0; k < rows; ++k) {
        int i = k;
        int j = 0;
        while (i >= 0 && j < cols) {
            std::cout << matrix[i][j] << " ";
            --i;
            ++j;
        }
        std::cout << std::endl;
    }

    // Iterate over the lower half of the matrix diagonals
    for (int k = 1; k < cols; ++k) {
        int i = rows - 1;
        int j = k;
        while (i >= 0 && j < cols) {
            std::cout << matrix[i][j] << " ";
            --i;
            ++j;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    printMatrixDiagonal(matrix);

    return 0;
}
