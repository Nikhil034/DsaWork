#include <iostream>
#include <vector>
#include <unordered_map>

std::string findKthDistinctString(std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string, int> countMap;
    std::vector<std::string> distinctStrings;

    for (const std::string& str : arr) {
        if (countMap.find(str) == countMap.end()) {
            // This is a distinct string, add it to the vector
            distinctStrings.push_back(str);
        }
        countMap[str]++;
    }

    if (k <= distinctStrings.size()) {
        return distinctStrings[k - 1];
    } else {
        return "";
    }
}

int main() {
    std::vector<std::string> arr = {"apple", "banana", "cherry", "apple", "date", "banana"};
    int k = 3;
    std::string result = findKthDistinctString(arr, k);

    std::cout << "The " << k << "th distinct string is: " << result << std::endl;

    return 0;
}
