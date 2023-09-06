#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,tar,sum=0,count=0;
    vector<int>vec;
    cout<<"Enter size of array=";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter a value=";
        cin>>arr[i];
    }

    cout<<"Enter target value=";
    cin>>tar;

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(sum==tar)
        {
            count++;
            sum=0;
        }
        
    }

    cout<<"The total number of ways is"<<count;



    return 0;
}
