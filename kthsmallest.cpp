#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int KthSmallelement(vector<int>&vec,int k)
{
    int n=vec.size();
    sort(vec.begin(), vec.end());

    for(int i=0;i<n;i++)
    {
        if(i==k-1)
        {
            return vec[i];
        }
    }


}



int main(){
    
    vector<int>vec;
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(4);
    vec.push_back(20);
    vec.push_back(15);

    int k;
    cout<<"Enter kth smallest element you find=";
    cin>>k;

    cout<<KthSmallelement(vec,k);

    return 0;
}