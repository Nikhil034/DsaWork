#include <iostream>
#include <algorithm>
using namespace std;

bool canPlaceCows(int positions[], int n, int cows, int minDistance) {
    int lastPosition = positions[0];
    int placedCows = 1;

    for (int i = 1; i < n; i++) {
        if (positions[i] - lastPosition >= minDistance) {
            placedCows++;
            lastPosition = positions[i];
        }
    }

    return placedCows >= cows;
}

int aggressiveCows(int positions[], int n, int cows) {
    sort(positions, positions + n);

    int low = 0;
    int high = positions[n - 1] - positions[0];
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(positions, n, cows, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n, cows;
    cin >> n >> cows;

    int positions[n];
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    int maxMinDistance = aggressiveCows(positions, n, cows);
    cout << "Maximum minimum distance: " << maxMinDistance << endl;

    return 0;
}
