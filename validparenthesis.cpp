#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isValidParenthesis(string s)
{
    int slen=s.length();
    int flag=0;

    for(int i=0;i<slen;i++)
    {
        for(int j=i+1;j<slen;j++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
               if(s[j]==')' || s[j]==']' || s[j]=='}')
               {
                 flag=1;
                 continue;
               }
               else
               {
                flag=0;
               }
            }
        }
        
    }

    if(flag==1){
        return true;
    }
    else
    {
        return false;
    }
}

int main(){

    string ch;

    cout<<"Enter a parenthessis value:-";
    cin>>ch;

    cout<<isValidParenthesis(ch);    
    return 0;
}