#include <iostream>
#include <vector>

using namespace std;

int maximumSwap(int num) {
    // Convert integer to vector of digits
    vector<int> digits;
    while (num > 0) {
        digits.insert(digits.begin(), num % 10);
        num /= 10;
    }

    // Find the maximum digit and its index
    int n = digits.size();
    vector<int> maxIndex(n, -1);
    maxIndex[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        if (digits[i] > digits[maxIndex[i + 1]]) {
            maxIndex[i] = i;
        } else {
            maxIndex[i] = maxIndex[i + 1];
        }
    }

    // Iterate through the digits to find the rightmost smaller digit
    for (int i = 0; i < n - 1; ++i) {
        if (digits[i] < digits[maxIndex[i + 1]]) {
            // Swap the digits
            swap(digits[i], digits[maxIndex[i + 1]]);
            
            // Convert the vector back to integer and return
            int result = 0;
            for (int digit : digits) {
                result = result * 10 + digit;
            }
            return result;
        }
    }

    // If no swap is needed, return the original number
    return num;
}

int main() {
    // Example usage
    int num = 209;
    int result = maximumSwap(num);
    
    cout << "Original number: " << num << endl;
    cout << "Maximum valued number: " << result << endl;

    return 0;
}
