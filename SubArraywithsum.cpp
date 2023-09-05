#include<iostream>
using namespace std;

int main() {
    int n, s;
    cout << "Enter the size of array=";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value index " << i << "=";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nEnter sum value=";
    cin >> s;

    int st = -1, end = -1;  // Initialize start and end to -1

    for (int i = 0; i < n; i++) {
        int sum = 0;  // Reset sum for each new i
        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == s) {
                st = i+1;
                end = j+1;
                break;
            }
            else if (sum > s) {
                break;  // If sum exceeds s, no need to continue with this i
            }
        }
        if (st != -1) {
            break;  // If a valid subarray is found, exit the loop
        }
    }

    if (st == -1) {
        cout << "No subarray found with the given sum." << endl;
    }
    else {
        cout << "Start index " << st << " and ending index " << end << " that sum is =" << s << endl;
    }

    return 0;
}
