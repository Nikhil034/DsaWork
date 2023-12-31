#include <iostream>
#include <vector>
#include <algorithm>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
    int n = triangle.size();

    // Starting from the second last row and moving upwards
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            // Update each element with the minimum path sum
            triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // The top of the triangle will contain the minimum path sum
    return triangle[0][0];
}

int main() {
    std::vector<std::vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    int minPathSum = minimumTotal(triangle);
    std::cout << "The minimum path sum from top to bottom is: " << minPathSum << std::endl;

    return 0;
}
