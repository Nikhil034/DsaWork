#include <iostream>
#include <vector>
#include <algorithm>

int maximumUnits(std::vector<std::vector<int>>& boxTypes, int truckSize) {
    // Sort boxTypes by units per box in descending order
    std::sort(boxTypes.begin(), boxTypes.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] > b[1];
    });

    int totalUnits = 0;

    for (const std::vector<int>& box : boxTypes) {
        int boxes = box[0];
        int units = box[1];

        if (truckSize >= boxes) {
            // If we can add all boxes of the current type
            totalUnits += boxes * units;
            truckSize -= boxes;
        } else {
            // If we can only add a portion of the boxes of the current type
            totalUnits += truckSize * units;
            break; // We've filled the truck to its limit
        }
    }

    return totalUnits;
}

int main() {
    std::vector<std::vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;
    int maxUnits = maximumUnits(boxTypes, truckSize);
    std::cout << "Maximum total units: " << maxUnits << std::endl;
    return 0;
}
