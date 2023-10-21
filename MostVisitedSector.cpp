#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mostVisited(int n, vector<int>& rounds) {
    vector<int> sectorVisits(n + 1, 0); // Initialize sector visit counts.

    int m = rounds.size();
    for (int i = 1; i < m; i++) {
        int start = rounds[i - 1];
        int end = rounds[i];

        // Increment the visit count for sectors covered by the current round.
        while (start != end) {
            sectorVisits[start]++;
            start = (start % n) + 1; // Move in a circular track.
        }
    }

    // Find the maximum visit count.
    int maxVisits = *max_element(sectorVisits.begin(), sectorVisits.end());

    vector<int> mostVisitedSectors;
    for (int i = 1; i <= n; i++) {
        if (sectorVisits[i] == maxVisits) {
            mostVisitedSectors.push_back(i);
        }
    }

    return mostVisitedSectors;
}

int main() {
    int n = 4;
    vector<int> rounds = {1, 3, 1, 2};
    
    vector<int> result = mostVisited(n, rounds);

    cout << "Most visited sectors: ";
    for (int sector : result) {
        cout << sector << " ";
    }
    cout << endl;

    return 0;
}
