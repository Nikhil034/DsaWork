#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[4]={1,2,5,7};
    vector<int>vec;
    int len=arr[sizeof(arr)/sizeof(arr[0])-1];
    int elm=0,is_find=0;

    for(int i=0;i<len;i++)
    {
        elm=i+1;

        for(int j=0;j<sizeof(arr)/sizeof(arr[0]);j++)
        {
           
           if(arr[j]==elm)
           {
             is_find=1;
             break;
           }
           else
           {
             is_find=0;
           }
        }

        if(is_find==0){
           vec.push_back(elm);
        }
    }

    for(int k=0;k<vec.size();k++)
    {
        cout<<vec[k]<<" ";
    }

    return 0;
}