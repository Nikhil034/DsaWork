#include<iostream>
#include<bits/stdc++.h>
#include<cstring>

using namespace std;

int solve(string str, int i, int j)
    {
        if (i == j) //  base case when index is same
            return 1;
 
        if (i > j)
            return 0;

            
        
        if (str[i]==str[j]) {
 
            return 1 + solve(str, i + 1, j)
                + solve(str, i, j - 1);
        }
 
        else
            return solve(str, i + 1, j)
                + solve(str, i, j - 1)
                - solve(str, i + 1, j - 1);
    }

int main(){
    


    cout<<solve("aab",0,2);
    return 0;
}