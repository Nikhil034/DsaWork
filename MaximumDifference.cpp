#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cout<<"Enter a size of array:-";
    cin>>n;

   int arr[n],mx,flag=0;
   vector<int>vec;

   for(int i=0;i<n;i++)
   {
    cin>>arr[i];
   }


   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
    {
        if(i<j && arr[i]<arr[j])
        {
            mx=arr[j]-arr[i];
            vec.push_back(mx);
            flag=1;
        }
    }
   }

   if(flag==1){
      cout << "\nMax Element = "
         << *max_element(vec.begin(), vec.end());
   }
   else{
    cout<<-1;
   }


    return 0;
}