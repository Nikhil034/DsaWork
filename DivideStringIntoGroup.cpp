#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s, str = "";
    char ch = 'X';
    int k = 3;
    vector<string> vec;

    cout << "Enter your string=";
    getline(cin, s); // Use getline to read the entire line

    for (int i = 0; i < s.length(); i++) {
        if (str.length() < k) {
            str += s[i];
        } else {
            vec.push_back(str);
            str = "";
            i--;
        }
    }


    if(str.length()!=k){
        while(str.length()<k){
            str+=ch;
        }
    }
    vec.push_back(str);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}
