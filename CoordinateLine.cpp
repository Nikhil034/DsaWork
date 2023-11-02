#include <iostream>
#include <vector>

bool checkStraightLine(std::vector<std::vector<int>>& coordinates) {
    if (coordinates.size() < 2) {
        // If there are fewer than 2 points, they trivially form a straight line.
        return true;
    }

    // Calculate the slope between the first two points.
    int x1 = coordinates[0][0];
    int y1 = coordinates[0][1];
    int x2 = coordinates[1][0];
    int y2 = coordinates[1][1];
    int initialSlope = (x2 - x1) * (y2 - y1);

    for (int i = 2; i < coordinates.size(); i++) {
        x2 = coordinates[i][0];
        y2 = coordinates[i][1];

        // Calculate the slope between the current point and the first point.
        int currentSlope = (x2 - x1) * (y2 - y1);

        // If the slopes are not equal, the points do not form a straight line.
        if (currentSlope != initialSlope) {
            return false;
        }
    }

    // If all slopes are equal, the points form a straight line.
    return true;
}

int main() {
    std::vector<std::vector<int>> coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    
    if (checkStraightLine(coordinates)) {
        std::cout << "The coordinates form a straight line." << std::endl;
    } else {
        std::cout << "The coordinates do not form a straight line." << std::endl;
    }

    return 0;
}
