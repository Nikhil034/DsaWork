#include <iostream>
#include <vector>
#include <stack>

int findLengthOfShortestSubarray(std::vector<int>& arr) {
    int n = arr.size();
    
    // Find the leftmost increasing subarray
    int left = 0;
    while (left < n - 1 && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    // If the entire array is non-decreasing, return 0
    if (left == n - 1) {
        return 0;
    }
    
    // Find the rightmost increasing subarray
    int right = n - 1;
    while (right > 0 && arr[right] >= arr[right - 1]) {
        right--;
    }
    
    int minLen = std::min(n - left - 1, right);
    
    // Create a stack to maintain a non-decreasing sequence
    std::stack<int> st;
    
    // Traverse the elements on the left side
    for (int i = 0; i <= left; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            st.pop();
        }
        minLen = std::min(minLen, i + 1 + (st.empty() ? 0 : left - st.top()));
    }
    
    return minLen;
}

int main() {
    std::vector<int> arr = {1, 3, 4, 2, 2, 2, 2, 2};
    int result = findLengthOfShortestSubarray(arr);
    std::cout << result << std::endl; // Output: 3
    return 0;
}
