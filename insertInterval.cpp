#include <iostream>
#include <vector>

using namespace std;

// Function to insert an interval into a list of intervals
vector<pair<int, int>> insertInterval(vector<pair<int, int>>& intervals, pair<int, int> newInterval) {
    vector<pair<int, int>> result;
    int i = 0;
    int n = intervals.size();

    // Add intervals that come before the new interval
    while (i < n && intervals[i].second < newInterval.first) {
        result.push_back(intervals[i]);
        i++;
    }

    // Merge intervals that overlap with the new interval
    while (i < n && intervals[i].first <= newInterval.second) {
        newInterval.first = min(newInterval.first, intervals[i].first);
        newInterval.second = max(newInterval.second, intervals[i].second);
        i++;
    }

    // Add the merged interval
    result.push_back(newInterval);

    // Add remaining intervals
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }

    return result;
}

int main() {
    // Example list of intervals
    vector<pair<int, int>> intervals = {{1, 3}, {6, 9}};
    pair<int, int> newInterval = {2, 5};

    // Insert the new interval
    vector<pair<int, int>> updatedIntervals = insertInterval(intervals, newInterval);

    // Display the updated intervals
    cout << "Updated Intervals: ";
    for (const auto& interval : updatedIntervals) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;

    return 0;
}
