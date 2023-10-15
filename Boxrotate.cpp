#include <iostream>
#include <vector>

std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& box) {
    int m = box.size(); // Number of rows
    int n = box[0].size(); // Number of columns

    std::vector<std::vector<char>> rotatedBox(n, std::vector<char>(m, '.')); // Initialize the rotated box

    for (int col = 0; col < n; col++) {
        int fallRow = m - 1; // Start from the bottom
        for (int row = m - 1; row >= 0; row--) {
            char cell = box[row][col];

            if (cell == '#') {
                // Simulate stone falling
                int newRow = fallRow;
                while (newRow < m - 1 && rotatedBox[newRow + 1][col] == '.') {
                    newRow++;
                }

                rotatedBox[newRow][col] = '#';
                fallRow = newRow - 1; // Update fallRow
            } else if (cell == '*') {
                fallRow = row - 1; // Reset fallRow
            }
        }
    }

    return rotatedBox;
}

int main() {
    // Example input matrix
    std::vector<std::vector<char>> box = {
        {'#', '.', '*', '.'},
        {'#', '#', '*', '.'},
        {'#', '#', '*', '*'},
    };

    // Rotate the box
    std::vector<std::vector<char>> rotatedBox = rotateTheBox(box);

    // Print the rotated box
    for (int i = 0; i < rotatedBox.size(); i++) {
        for (int j = 0; j < rotatedBox[0].size(); j++) {
            std::cout << rotatedBox[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
