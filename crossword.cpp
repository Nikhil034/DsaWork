#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    char arr[5][5];
    string str;
    int sl;
    str="hello";
    sl=str.length();
    
    
    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;c++)
        {
            cout<<"Enter a sign (+) | (-)";
            cin>>arr[r][c];
        }
    }
    int x=0;

    
    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;c++)
        {
           if(arr[r][c]=='-' && x!=sl)
           {
              arr[r][c]=str[x];
              x++;
           }
        }
        
    }

    cout<<"----------CROSS WORD----------\n";

    for(int r=0;r<5;r++)
    {
        for(int c=0;c<5;c++)
        {
            cout<<arr[r][c]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}