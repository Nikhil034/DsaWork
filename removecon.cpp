#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){


    string s,ans;
    cout<<"Enter a string:-";
    cin>>s;

    ans=s[0];
    

    for(int i=0;i<s.length();i++)
    {
        if(s[i]==s[i+1])
        {
           cout<<"";
        }
        else
        {
         ans=ans+s[i+1]; 
        }
    }

    cout<<"Answer is:-"<<ans;


    return 0;
}