#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,sum=1,count=0;
    string str;
    cout<<"Enter a value=";
    cin>>n;

   for(int i=n;i>=1;i--)
   {

    if(n==0)
    {
        sum=0;
        str='0';
        break;
    }

    sum=sum*i;
   }
   
   str=to_string(sum);

   for(int i=0;i<str.length();i++)
   {

    if(sum==0)
    {
        break;
    }
    if(str[i]=='0')
    {
        count++;
    }
   }

   cout<<n <<"! = "<<sum<<","<<count<<"Traling zero!";

    return 0;
}