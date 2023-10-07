#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareCosts(const vector<int>& cost1, const vector<int>& cost2) {
    return cost1[0] - cost1[1] < cost2[0] - cost2[1];
}

int minCostToCity(vector<vector<int>>& costs) {
    // Sort the costs array based on the difference between aCost and bCost
    sort(costs.begin(), costs.end(), compareCosts);

    const int n = costs.size() / 2; // Number of people to be sent to each city
    int totalCost = 0;

    // Send the first n people to city A and the rest to city B
    for (int i = 0; i < costs.size(); i++) {
        if (i < n) {
            totalCost += costs[i][0]; // Send to city A
        } else {
            totalCost += costs[i][1]; // Send to city B
        }
    }

    return totalCost;
}

int main() {
    vector<vector<int>> costs = {{10, 20}, {30, 200}, {50, 10}, {70, 30}};
    int result = minCostToCity(costs);
    cout << result << endl; // Output: 150

    return 0;
}
