#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int swaps=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            swaps++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}



int main(){
    
    vector<int>vec;
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(3);

    cout<<minSwaps(vec);
    return 0;
}