#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int isValidParenthesis(string expression)
{
    // Write your code here.
    vector <char> stack;
    for(auto x:stack) {
        stack.push_back(x);
    }

    for(int i=0;i<expression.size();i++) {
        if(stack['(']==expression[')'] || stack['{']==expression['}'] || stack['['] == expression[']']) {
            return 1;
        }
    }
}

int main(){
    int x=isValidParenthesis("{()}");
    cout<<x;
    return 0;
}