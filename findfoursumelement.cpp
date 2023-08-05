#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    const int arraySize = 7;
    int arr[arraySize] = {1, 2, 3, 4, 5, 6, 7};
    int targetSum;

    std::cout << "Enter the target sum: ";
    std::cin >> targetSum;

    bool found = false;

    // Nested loop to find four elements with the target sum
    for (int i = 0; i < arraySize - 3; i++) {
        for (int j = i + 1; j < arraySize - 2; j++) {
            for (int k = j + 1; k < arraySize - 1; k++) {
                for (int l = k + 1; l < arraySize; l++) {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == targetSum) {
                        found = true;
                        std::cout << "Elements found: " << arr[i] << ", " << arr[j] << ", " << arr[k] << ", " << arr[l] << std::endl;
                    }
                }
            }
        }
    }

    if (!found) {
        std::cout << "No four elements found with the target sum." << std::endl;
    }

    return 0;
}
