#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    string str,ptr;
    vector<int>vec;

    cout<<"Enter a Text:-";
    cin>>str;

    cout<<"Enter your pattern:-";
    cin>>ptr;

    for(int i=0;i<str.length();i++)
    {
        for(int j=i;j<ptr.length();j++)
        {

            if(ptr[j]==str[i])
            {
                

            }


        }
    }



    return 0;
}