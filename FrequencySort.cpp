#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool customSort(std::pair<int, int> a, std::pair<int, int> b) {
    // Sort based on frequency in ascending order
    if (a.second != b.second) {
        return a.second < b.second;
    }
    
    // If frequencies are the same, sort based on value in descending order
    return a.first > b.first;
}

std::vector<int> frequencySort(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }
    
    std::vector<std::pair<int, int>> freqArr;
    for (const auto& entry : freq) {
        freqArr.push_back(entry);
    }
    
    // Custom sort using the customSort function
    std::sort(freqArr.begin(), freqArr.end(), customSort);
    
    std::vector<int> result;
    for (const auto& pair : freqArr) {
        int num = pair.first;
        int frequency = pair.second;
        for (int i = 0; i < frequency; i++) {
            result.push_back(num);
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {4, 2, 2, 8, 3, 3, 1};
    std::vector<int> result = frequencySort(nums);

    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
