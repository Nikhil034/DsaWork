#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

int maxProfit(std::vector<int>& prices) {
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); ++i) {
        // If the current price is higher than the previous day's price, we can make a profit
        if (prices[i] > prices[i - 1]) {
            maxProfit += prices[i] - prices[i - 1];
        }
    }

    return maxProfit;
}

int main() {
    // Example usage
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);

    std::cout << "Maximum profit: " << result << std::endl;

    return 0;
}
