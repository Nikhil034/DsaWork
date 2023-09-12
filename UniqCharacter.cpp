#include<iostream>
using namespace std;

int main(){
    string str;
    int uniq = -1; // Initialize uniq to -1
    int flag = 1;  // Initialize flag to 1
    cout << "Enter a string: ";
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        flag = 1;  // Reset flag to 1 for each character

        for(int j = 0; j < str.length(); j++) {
            if(i != j && str[i] == str[j]) {
                flag = 0;  // If a duplicate is found, set flag to 0
                break;
            }
        }

        if(flag == 1) {
            uniq = i;  // Store the index of the unique character
            break;     // Break the loop as a unique character is found
        }
    }

    cout << "\nSTRING IS: " << str;
    
    if (uniq != -1) {
        cout << "\nUNIQUE CHARACTER IS: " << str[uniq] << " at index " << uniq;
    } else {
        cout << "\nNo unique character found.";
    }

    return 0;
}
