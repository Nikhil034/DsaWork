#include <iostream>
#include <vector>

std::vector<std::vector<int>> generatePascalsTriangle(int numRows) {
    std::vector<std::vector<int>> triangle(numRows);
    
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1; // First and last element in each row is 1
        
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; // Calculate middle elements
        }
    }
    
    return triangle;
}

int main() {
    int numRows = 5; // Change this to generate more rows
    std::vector<std::vector<int>> triangle = generatePascalsTriangle(numRows);

    // Print the generated Pascal's triangle
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
