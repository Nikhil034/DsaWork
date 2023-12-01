#include <iostream>
#include <vector>

// Function to find the next state of the grid based on Game of Life rules
std::vector<std::vector<int>> gameOfLife(std::vector<std::vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    std::vector<std::vector<int>> next(m, std::vector<int>(n, 0));

    int dirX[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dirY[] = {1, 1, 0, -1, -1, -1, 0, 1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int liveNeighbors = 0;
            for (int k = 0; k < 8; ++k) {
                int x = i + dirX[k];
                int y = j + dirY[k];
                if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1) {
                    liveNeighbors++;
                }
            }

            if (board[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    next[i][j] = 0; // cell dies due to under-population or over-population
                } else {
                    next[i][j] = 1; // cell lives on to the next generation
                }
            } else {
                if (liveNeighbors == 3) {
                    next[i][j] = 1; // dead cell becomes alive due to reproduction
                }
            }
        }
    }

    return next;
}

// Function to print the grid
void printGrid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Example usage
int main() {
    std::vector<std::vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    std::cout << "Initial state:" << std::endl;
    printGrid(board);

    std::vector<std::vector<int>> next = gameOfLife(board);

    std::cout << "\nNext state:" << std::endl;
    printGrid(next);

    return 0;
}
