#include <iostream>
#include <vector>

using namespace std;

// Helper function to perform DFS and mark visited land cells
void dfs(vector<vector<char>>& grid, int row, int col) {
    // Check boundary conditions and if the cell is land
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
        return;
    }

    // Mark the current cell as visited
    grid[row][col] = '0';

    // Recursively explore neighboring land cells (up, down, left, right)
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) {
        return 0;
    }

    int numIslands = 0;

    // Traverse the grid and start DFS when unvisited land ('1') is found
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                numIslands++;
                dfs(grid, i, j); // Mark the current island and its neighbors as visited
            }
        }
    }

    return numIslands;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
