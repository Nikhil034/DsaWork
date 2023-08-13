#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5; // Size of the crossword grid

void printGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlaceHorizontal(vector<vector<char>>& grid, int row, int col, string word) {
    if (col + word.size() > SIZE) {
        return false;
    }
    for (int i = 0; i < word.size(); ++i) {
        if (grid[row][col + i] != '-' && grid[row][col + i] != word[i]) {
            return false;
        }
    }
    return true;
}

void placeHorizontal(vector<vector<char>>& grid, int row, int col, string word) {
    for (int i = 0; i < word.size(); ++i) {
        grid[row][col + i] = word[i];
    }
}

bool solveCrossword(vector<vector<char>>& grid, vector<string>& words, int wordIndex) {
    if (wordIndex == words.size()) {
        return true; // All words are placed
    }
    
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (grid[row][col] == '-' || grid[row][col] == words[wordIndex][0]) {
                if (canPlaceHorizontal(grid, row, col, words[wordIndex])) {
                    vector<vector<char>> backup = grid; // Backup grid state
                    placeHorizontal(grid, row, col, words[wordIndex]);
                    
                    if (solveCrossword(grid, words, wordIndex + 1)) {
                        return true; // Move to the next word
                    }
                    
                    grid = backup; // Restore grid state
                }
            }
        }
    }
    
    return false; // Unable to place the current word
}

int main() {
    vector<vector<char>> grid(SIZE, vector<char>(SIZE, '-'));
    vector<string> words = {"hello", "world", "cross", "grid"};
    
    if (solveCrossword(grid, words, 0)) {
        cout << "Solution found:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}
