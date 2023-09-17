#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    vector<int>vec;
    cout<<"Enter a size of array=";
    cin>>n;

   int arr[n],i,elm;

   for(i=0;i<n;i++)
   {
    cout<<"Enter a value=";
    cin>>arr[i];
   }


  for(i=0;i<n;i++)
  {
     elm=arr[i];

     if(elm>arr[i+1] && elm>arr[i-1])
     {
        vec.push_back(i);
     }

  }

  cout<<"Peak element index at="<<vec[vec.size()-1];

  


    return 0;
}