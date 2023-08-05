#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[6]={5,20,3,2,50,80};
    vector<int>vec;
    int n=78;

    for(int i=0;i<=sizeof(arr)/sizeof(arr[0]);i++)
    {
        for(int j=0;j<=sizeof(arr)/sizeof(arr[0]);j++)
        {
              
              if(abs(arr[i]-arr[j])==n)
              {
                
                  vec.push_back(arr[i]);
                  vec.push_back(arr[j]);
                  
              }
        }
    }

    cout<<"-----Pair is list below---------";

    for(int i=0;i<2;i++)
    {
        cout<<vec[i]<<",";
    }



    return 0;
}