#include <iostream>
#include <unordered_set>
#include <vector>

bool checkIfDoubleExists(std::vector<int>& arr) {
    std::unordered_set<int> seen;
    for (int num : arr) {
        if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    std::vector<int> arr = {10, 2, 5, 3};
    if (checkIfDoubleExists(arr)) {
        std::cout << "Yes, there exist two indices i and j such that arr[i] == 2 * arr[j]." << std::endl;
    } else {
        std::cout << "No, there does not exist such two indices i and j." << std::endl;
    }
    return 0;
}
