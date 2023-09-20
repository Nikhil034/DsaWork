#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string username;
    cin >> username;

    set<char> distinctChars;

    for (char c : username) {
        distinctChars.insert(c);
    }

    if (distinctChars.size() % 2 == 0) {
        cout << "CHAT WITH HER!" << endl;

    } else {
         cout << "IGNORE HIM!" << endl;
    }

    return 0;
}
