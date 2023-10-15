#include<iostream>
using namespace std;

int main(){
    string str;
    char ch;
    int i, index = -1;
    bool isUnique;

    cout << "Enter a string=";
    cin >> str;

    for (i = 0; i < str.length(); i++) {
        ch = str[i];
        isUnique = true;

        for (int j = 0; j < str.length(); j++) {
            if (ch == str[j] && i != j) {
                isUnique = false;
                break; // No need to continue checking the rest of the characters
            }
        }

        if (isUnique) {
            index = i;
            break; // Found the first unique character, no need to check further
        }
    }

    cout << "INDEX RETURN IS=" << index;

    return 0;
}
