#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> findCommonElements(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
    std::vector<int> commonElements;

    // Sort the arrays
    std::sort(arr1, arr1 + size1);
    std::sort(arr2, arr2 + size2);
    std::sort(arr3, arr3 + size3);

    // Initialize three pointers for array traversal
    int i = 0, j = 0, k = 0;

    // Loop until one of the arrays reaches its end
    while (i < size1 && j < size2 && k < size3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            // Found a common element
            commonElements.push_back(arr1[i]);

            // Move the pointers to the next different elements
            while (i < size1 && arr1[i] == commonElements.back()) i++;
            while (j < size2 && arr2[j] == commonElements.back()) j++;
            while (k < size3 && arr3[k] == commonElements.back()) k++;
        } else {
            // Increment the pointer of the smallest element
            int minElement = std::min({arr1[i], arr2[j], arr3[k]});
            if (arr1[i] == minElement) i++;
            if (arr2[j] == minElement) j++;
            if (arr3[k] == minElement) k++;
        }
    }

    return commonElements;
}

int main() {
    int arr1[] = {1,5,5};
    int arr2[] = {3,4,5,5,10};
    int arr3[] = {5,5,10,20};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    std::vector<int> commonElements = findCommonElements(arr1, size1, arr2, size2, arr3, size3);

    if (commonElements.size() >= 2) {
        std::cout << "Common elements: " << commonElements[0] << ", " << commonElements[1] << std::endl;
    } else {
        std::cout << "No common elements found." << std::endl;
    }

    return 0;
}
