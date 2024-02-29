#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int maxCandies(vector<int>& candyType) {
    unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
    int maxAllowed = candyType.size() / 2;
    return min((int)uniqueCandies.size(), maxAllowed);
}

// Example usage
int main() {
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    int maxTypes = maxCandies(candyType);
    cout << "Maximum number of different types of candies Alice can eat: " << maxTypes << endl;
    return 0;
}
