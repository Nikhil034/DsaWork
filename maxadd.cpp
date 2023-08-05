#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[5]={1,2,3,8,9};
    vector<int>vec;
    int val,val2;


    for(int i=0;i<4;i++)
    {
        if(i==0)
        {
            val=arr[0]-arr[i+1];
            vec.push_back(abs(val));
        }
        else
        {
            val=arr[i]-arr[i+1];
            vec.push_back(abs(val));
            
        }
    }

    for(int k=0;k<vec.size();k++)
    {
        cout<<vec[k]<<" ";
    }

    cout << "Max Difference of adjecent elememnt = " << *max_element(vec.begin(), vec.end());

    return 0;
}