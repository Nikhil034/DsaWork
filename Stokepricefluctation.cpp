#include <iostream>
#include <queue>
#include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

class StockPrice {
private:
    unordered_map<int, int> prices;
    priority_queue<pair<int, int>> maxPrices;  // Max heap
    priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> minPrices;  // Min heap

public:
    StockPrice() {
    }

    void update(int timestamp, int price) {
        prices[timestamp] = price;
        maxPrices.push({price, timestamp});
        minPrices.push({price, timestamp});
    }

    int current() {
        return prices.rbegin()->second;  // Get the price associated with the latest timestamp
    }

    int maximum() {
        while (!maxPrices.empty() && prices[maxPrices.top().second] != maxPrices.top().first) {
            maxPrices.pop();  // Remove outdated entries
        }
        return maxPrices.top().first;
    }

    int minimum() {
        while (!minPrices.empty() && prices[minPrices.top().second] != minPrices.top().first) {
            minPrices.pop();  // Remove outdated entries
        }
        return minPrices.top().first;
    }
};

int main() {
    StockPrice obj;

    obj.update(1, 10);
    obj.update(2, 5);
    obj.update(1, 3);
    obj.update(4, 8);

    int param_1 = obj.current();  // Should print 8
    int param_2 = obj.maximum();  // Should print 10
    int param_3 = obj.minimum();  // Should print 3

    cout << "Current: " << param_1 << endl;
    cout << "Maximum: " << param_2 << endl;
    cout << "Minimum: " << param_3 << endl;

    return 0;
}
