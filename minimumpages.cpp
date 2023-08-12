#include <iostream>
#include <algorithm>
using namespace std;

bool isPossible(int arr[], int n, int m, int maxPages) {
    int studentsRequired = 1;
    int pagesAllocated = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) {
            return false;  // If a single book cannot be allocated, return false
        }

        if (pagesAllocated + arr[i] > maxPages) {
            studentsRequired++;
            pagesAllocated = arr[i];
            if (studentsRequired > m) {
                return false;  // If required students exceed m, return false
            }
        } else {
            pagesAllocated += arr[i];
        }
    }

    return true;
}

int allocatePages(int arr[], int n, int m) {
    int totalPages = 0;
    int maxPages = 0;

    for (int i = 0; i < n; i++) {
        totalPages += arr[i];
        maxPages = max(maxPages, arr[i]);
    }

    int low = maxPages;
    int high = totalPages;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minMaxPages = allocatePages(arr, n, m);
    cout << "Minimum maximum pages: " << minMaxPages << endl;

    return 0;
}
