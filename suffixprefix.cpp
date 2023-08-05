#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
Function to find the length of
Longest proper prefix that is also a suffix.
*/
void solve(string s){

    int ans = 0;
    int n = s.size();

    // Iterating over the length of prefix
    for (int l = 1; l<=n-1; l++){
        string prefix = "";
        string suffix = "";

        // Storing prefix of the given length
        for(int i=0; i<l; i++){
            prefix += s[i];
        }

        // Storing suffix of the given length
        for(int i=n-l; i<n; i++){
            suffix += s[i];
        }

        // If prefix and suffix are same, update answer
        if (prefix == suffix){
            ans = l;
        }
    }

    // Printing the longest proper prefix that is also a suffix.
    cout<<ans<<endl;
}

// Driver Code
int main(){
    string s = "xyxyxy";
    solve(s);
}