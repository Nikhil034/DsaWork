#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0; // If the input vector is empty, there are no duplicates to remove.
    }

    int uniqueIndex = 0; // Index to track unique elements

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[uniqueIndex]) {
            uniqueIndex++;
            nums[uniqueIndex] = nums[i];
        }
    }

    return uniqueIndex + 1; // Return the new length of the modified array
}

int main() {
    vector<int> nums;
    int n, num;

    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    cout << "Enter the sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums.push_back(num);
    }

    int newLength = removeDuplicates(nums);

    cout << "New Length: " << newLength << endl;
    cout << "Modified Array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
