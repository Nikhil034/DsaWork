#include<iostream>
#include<string.h>

using namespace std;

int main(){
   
    string str, str2 = "";
    int flag = 0;

    cout << "Enter a string with white spaces: ";
    getline(cin, str);

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ' || str[i] == ':' || str[i] == ',')
        {
            continue;
        }
        else
        {
            str2 += tolower(str[i]);
        }
    }

    int l = 0;
    int h = str2.length() - 1;
  
    // Keep comparing characters while they are the same
    while (h > l) {
        if (str2[l++] != str2[h--]) {
            flag = 1;
            break; // Exit the loop as soon as a mismatch is found
        }
    }

    if (flag == 0){
        cout << "\nPALINDROME STRING!";
    }
    else{
        cout << "\nNOT A PALINDROME STRING!";
    }

    return 0;
}
