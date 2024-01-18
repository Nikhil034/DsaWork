#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    
    for (char digit : num) {
        while (k > 0 && !st.empty() && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    
    // Handle the case where k is not fully used
    while (k > 0) {
        st.pop();
        k--;
    }
    
    // Construct the result string
    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    // Remove leading zeros
    size_t nonZeroIndex = result.find_first_not_of('0');
    result = (nonZeroIndex != string::npos) ? result.substr(nonZeroIndex) : "0";
    
    return result.empty() ? "0" : result;
}

int main() {
    string num = "1432219";
    int k = 3;

    string result = removeKdigits(num, k);

    cout << "The smallest possible integer after removing " << k << " digits is: " << result << endl;

    return 0;
}
