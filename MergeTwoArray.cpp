#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr1[9] = {0, 2, 0, 3, 0, 5, 6, 0, 0};
    int arr2[5] = {1, 8, 9, 10, 15};
    vector<int> vec;

    // Add non-zero elements from arr1 starting from index 1
    for (int i = 1; i < sizeof(arr1) / sizeof(arr1[0]); i++) {
        if (arr1[i] != 0) {
            vec.push_back(arr1[i]);
        }
    }

    // Add elements from arr2
    for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
        vec.push_back(arr2[i]);
    }

    // Sort the vector in ascending order
    sort(vec.begin(), vec.end());

    // Print the sorted vector
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}
