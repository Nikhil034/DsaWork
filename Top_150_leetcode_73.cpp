#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& board, int i, int j) {
    int m = board.size();
    int n = board[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
        return;
    }

    board[i][j] = 'T'; // Temporarily mark 'O's in the region

    // DFS in all four directions
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0) return;
    int n = board[0].size();

    // Check 'O's on the boundary and perform DFS
    for (int i = 0; i < m; ++i) {
        if (board[i][0] == 'O') dfs(board, i, 0);
        if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
        if (board[0][j] == 'O') dfs(board, 0, j);
        if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
    }

    // Mark surrounded regions and flip 'O's to 'X's
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            } else if (board[i][j] == 'T') {
                board[i][j] = 'O';
            }
        }
    }
}

int main() {
    // Example usage
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    cout << "Original board:" << endl;
    for (auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    solve(board);

    cout << "\nBoard after capturing surrounded regions:" << endl;
    for (auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
