#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxPointsOnLine(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) {
        return n; // If there are 0, 1, or 2 points, they all lie on the same line
    }

    int maxPoints = 2; // Initialize with at least two points

    for (int i = 0; i < n; ++i) {
        unordered_map<double, int> slopeCount; // Slope to count mapping
        int samePointCount = 0; // Count of points with the same coordinates

        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    samePointCount++;
                } else {
                    double slope = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                    slopeCount[slope]++;
                }
            }
        }

        int localMax = samePointCount; // Add points with the same coordinates

        for (auto& entry : slopeCount) {
            localMax = max(localMax, entry.second + samePointCount);
        }

        maxPoints = max(maxPoints, localMax);
    }

    return maxPoints;
}

int main() {
    // Example usage
    vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}, {4, 1}, {5, 1}};
    cout << "Maximum number of points on the same line: " << maxPointsOnLine(points) << endl;

    return 0;
}
