#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

            
    vector<int>vec;
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(6);
    vec.push_back(2);
  
    
    int i = 0;
    int n = vec.size();
    int j = n - 1;
    int area = 0;

    while(j > i)
    {
            area = max(area, min(vec[i],vec[j]) * abs(i - j));
            if(vec[i] < vec[j]) i++;
            else j--;
    }
    cout<<"Answer is="<<area;

    

    return 0;
}