#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string revstr(char *str1) {
    // declare variable
    int i, len, temp;
    len = strlen(str1);

    // use strlen() to get the length of str string
    // use or loop to iterate the string
    for(i = 0;i < len/2;i++)
    {
        //temp variable use to temporary hold the string
        temp = str1[i];
        str1[i] = str1[len - i - 1];
        str1[len - i - 1] = temp;
    }
    return str1;
}

int main(){

    string str,str2;
    int flag=0;

    cout<<"Enter a string=";
    cin>>str;

    for(int i=str.length()-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
           str2+=str[j];
        }
        cout<<"\nindex i="<<i<<str2;
        str.erase(remove(str.begin(), str.end(), str[i]), str.end());
        str2="";
    }


    return 0;
}