#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int>vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

     vector<vector<int>>vect;

     for(int i=0;i<vec.size();i++)
     {
        for(int k=i;k<vec.size();k++)
        {
            vect[i][k]=vec[i];
            vect[i][k+1]=vec[k];
        }
     }

     for(int g=0;g<vect.size();g++)
     {
        for(int h=0;h<vect[g].size();h++)
        {
            cout<<vect[g][h]<<","<<" ";
        }
     }
   

    return 0;
}