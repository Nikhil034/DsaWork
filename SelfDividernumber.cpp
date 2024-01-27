#include <iostream>
#include <vector>

using namespace std;

// Function to check if a number is self-dividing
bool isSelfDividing(int num) {
    int originalNum = num;
    
    while (num > 0) {
        int digit = num % 10;
        
        if (digit == 0 || originalNum % digit != 0) {
            return false;
        }
        
        num /= 10;
    }
    
    return true;
}

// Function to find self-dividing numbers in the given range
vector<int> selfDividingNumbers(int left, int right) {
    vector<int> result;

    for (int i = left; i <= right; ++i) {
        if (isSelfDividing(i)) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int left, right;

    // Input the range [left, right]
    cout << "Enter the left and right boundaries of the range: ";
    cin >> left >> right;

    // Find and print self-dividing numbers in the range
    vector<int> result = selfDividingNumbers(left, right);

    cout << "Self-dividing numbers in the range [" << left << ", " << right << "]: ";
    for (int num : result) {
        cout << num << " ";
    }
    
    cout << endl;

    return 0;
}
