#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string str;
    char dup;
    int count=0;

    cout<<"Enter a string=";
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        for(int j=0;j<str.length();j++)
        {
            if(str[i]==str[j+1])
            {
                dup=str[j+1];
                count++;
            }

        }
        cout<<"\ncharcter["<<dup<<"]"<<" count="<<count;
        count=0;
    }

    return 0;
}