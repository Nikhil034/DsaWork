#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (const string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            
            if (token == "+")
                st.push(operand1 + operand2);
            else if (token == "-")
                st.push(operand1 - operand2);
            else if (token == "*")
                st.push(operand1 * operand2);
            else if (token == "/")
                st.push(operand1 / operand2);
        } else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
