#include <iostream>
#include <vector>
#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    std::unordered_set<std::string> seen;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char current = board[i][j];
            if (current != '.') {
                std::string row = "row " + std::to_string(i) + " has " + current;
                std::string col = "col " + std::to_string(j) + " has " + current;
                std::string box = "box " + std::to_string(i / 3) + "-" + std::to_string(j / 3) + " has " + current;

                if (seen.find(row) != seen.end() ||
                    seen.find(col) != seen.end() ||
                    seen.find(box) != seen.end()) {
                    return false;
                }

                seen.insert(row);
                seen.insert(col);
                seen.insert(box);
            }
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        std::cout << "The Sudoku board is valid." << std::endl;
    } else {
        std::cout << "The Sudoku board is not valid." << std::endl;
    }

    return 0;
}
