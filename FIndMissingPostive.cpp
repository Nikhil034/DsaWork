#include <iostream>
#include <vector>
#include <algorithm>

int findMissingPositive(std::vector<int>& arr) {
    int minPositive = 1;

    // Sort the vector in ascending order
    std::sort(arr.begin(), arr.end());

    for (int num : arr) {
        if (num == minPositive) {
            minPositive++;
        } else if (num > minPositive) {
            return minPositive;
        }
    }

    return minPositive;
}

int main() {
    std::vector<int> inputArray = {1, 2, 3, 7, 10};
    int missingPositive = findMissingPositive(inputArray);
    std::cout << "Missing positive integer: " << missingPositive << std::endl;

    return 0;
}
