#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    int occu,flag=0;
    map<char,int>mp;
    char ch;

    cout<<"Enter your string=";
    cin>>str;

    for(int i=0;i<str.length();i++)
    {
       ch=str[i];

       if(mp.find(ch)!=mp.end())
       {
         mp[str[i]]++;
       }
       else
       {
        mp.insert({str[i],1});
       }

    }
    occu=mp[str[0]];
   

    
    for (const auto& x : mp) {

         if(x.second==occu)
         {
            flag=1;
         }
         else
         {
            flag=0;
        
         }

        // cout << x.first << ": " << x.second << "\n";
    }

    cout<<str<<" have equal number of occurence that return="<<flag;

    

    return 0;
}