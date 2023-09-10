#include<iostream>
using namespace std;

int main() {
    int n, uniq = 0, flag = 0;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter a value: ";
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        uniq = arr[i];
        flag = 0; // Reset flag for each new value

        for(int j = 0; j < n; j++) {
            if(i != j && uniq == arr[j]) {
                flag = 1;
                break; // Break the loop as soon as a duplicate is found
            }
        }

        if(flag == 0) {
            break; // Break the loop if no duplicate is found
        }
    }

    cout << "Unique single value is: " << uniq;

    return 0;
}
