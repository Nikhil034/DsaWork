#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int minHeight = std::min(height[left], height[right]);
        int currentWater = minHeight * (right - left);
        maxWater = std::max(maxWater, currentWater);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxWater;
}

int main() {
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; // Example height array

    int maxWater = maxArea(height);
    std::cout << "Maximum water that can be stored: " << maxWater << std::endl;

    return 0;
}
