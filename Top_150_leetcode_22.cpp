#include <iostream>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            return {left + 1, right + 1}; // Adjust indices to be 1-indexed
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    // If no solution found, return empty vector or handle it as needed
    return {};
}

int main() {
    std::vector<int> numbers = {2, 7, 11, 15, 18, 22, 30};
    int target = 33;

    std::vector<int> result = twoSum(numbers, target);

    if (!result.empty()) {
        std::cout << "Indices are: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No solution found!" << std::endl;
    }

    return 0;
}
