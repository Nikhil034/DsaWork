#include <iostream>
#include <vector>

// Size of the chessboard
const int N = 8;

// Arrays to represent possible moves for the knight
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// Function to check if a move is valid
bool isSafe(int x, int y, std::vector<std::vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

// Recursive function to solve the Knight's Tour
bool solveKnightTour(int x, int y, int move, std::vector<std::vector<int>>& board) {
    if (move == N * N) {
        return true; // All squares have been visited
    }

    for (int k = 0; k < 8; ++k) {
        int next_x = x + dx[k];
        int next_y = y + dy[k];
        
        if (isSafe(next_x, next_y, board)) {
            board[next_x][next_y] = move;
            
            if (solveKnightTour(next_x, next_y, move + 1, board)) {
                return true; // Move was successful
            }
            
            board[next_x][next_y] = -1; // Backtrack
        }
    }

    return false; // No valid move
}

// Function to solve the Knight's Tour problem
bool knightTour() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, -1));
    
    // Start at position (0, 0)
    board[0][0] = 0;
    
    if (!solveKnightTour(0, 0, 1, board)) {
        std::cout << "Solution does not exist" << std::endl;
        return false;
    }

    // Print the solution
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return true;
}

int main() {
    knightTour();
    return 0;
}
