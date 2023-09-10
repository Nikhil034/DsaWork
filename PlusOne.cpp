#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter a value: ";
        cin >> arr[i];
    }

    string str;
    for (int i = 0; i < n; i++) {
        str += to_string(arr[i]);
    }

    cout << "Concatenated string: " << str << endl;

    // Convert the concatenated string to an integer, increment by one, and convert back to a string
    int newsum = stoi(str) + 1;
    str = to_string(newsum);

    cout << "Final sum: " << str << endl;

    // Replace the original array with the digits of the final integer
    for (int i = 0; i < n; i++) {
        arr[i] = str[i] - '0';
    }

    cout << "Updated array: ";
    for (int i = 0; i < str.length(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
