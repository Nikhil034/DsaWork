#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter array size=";
    cin>>n;
    vector<int> vec;

    int arr[n],i,tar;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        vec.push_back(arr[i]);
    }

    cout<<"Target value=";
    cin>>tar;

     auto it = find(vec.begin(), vec.end(),
                   tar);
 
    if (it != vec.end()) {
        vec.erase(it);
    }
 

    vec.insert (vec.begin(),tar);

    for(i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }

    return 0;
}