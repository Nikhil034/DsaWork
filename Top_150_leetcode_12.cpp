#include <iostream>
#include <vector>

int minCandies(std::vector<int>& ratings) {
    int n = ratings.size();
    std::vector<int> candies(n, 1); // Initialize candies array with 1 (minimum)
    
    // Traverse from left to right
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1; // Give more candies to higher-rated child
        }
    }
    
    // Traverse from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1); // Ensure higher-rated child gets more candies
        }
    }
    
    // Sum up the total candies
    int totalCandies = 0;
    for (int num : candies) {
        totalCandies += num;
    }
    
    return totalCandies;
}

int main() {
    std::vector<int> ratings = {1, 0, 2};
    int minCandiesNeeded = minCandies(ratings);

    std::cout << "Minimum candies needed: " << minCandiesNeeded << std::endl;

    return 0;
}
