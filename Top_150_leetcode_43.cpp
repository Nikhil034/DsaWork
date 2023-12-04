#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    // Sort intervals based on the start time
    std::sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);

    for (const auto& interval : intervals) {
        if (interval[0] <= merged.back()[1]) {
            // Merge overlapping intervals
            merged.back()[1] = std::max(merged.back()[1], interval[1]);
        } else {
            // Add non-overlapping intervals
            merged.push_back(interval);
        }
    }

    return merged;
}

int main() {
    // Example intervals
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    // Merge overlapping intervals
    std::vector<std::vector<int>> mergedIntervals = mergeIntervals(intervals);

    // Output the merged intervals
    std::cout << "Merged intervals: ";
    for (const auto& interval : mergedIntervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
