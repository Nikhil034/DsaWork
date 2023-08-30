#include <iostream>
#include <vector>

using namespace std;

int maxSumPath(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    int sum1 = 0, sum2 = 0;
    int maxSum = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            sum1 += arr1[i];
            i++;
        } else if (arr1[i] > arr2[j]) {
            sum2 += arr2[j];
            j++;
        } else {
            maxSum += max(sum1, sum2) + arr1[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }

    while (i < arr1.size()) {
        sum1 += arr1[i];
        i++;
    }

    while (j < arr2.size()) {
        sum2 += arr2[j];
        j++;
    }

    maxSum += max(sum1, sum2);

    return maxSum;
}

int main() {
    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};
    
    int result = maxSumPath(arr1, arr2);
    cout << "Maximum sum path: " << result << endl;

    return 0;
}
