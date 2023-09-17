#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,i,is_start=0,index=0;
    vector<int>vec;

    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],tar=0;

   for(i=0;i<n;i++)
   {
      cout<<"Enter a value=";
      cin>>arr[i];
   }

   cout<<"Enter a target value=";
   cin>>tar;

   for(i=0;i<n;i++)
   {
     if(tar==arr[i])
     {
        is_start=1;
        index=i;
        vec.push_back(i);
        break;
     }

   }

   if(is_start==1)
   {
     for(i=index+1;i<n;i++)
     {
        if(tar==arr[i])
        {
            vec.push_back(i);
            break;
        }
     }
   }
   else
   {
     vec.push_back(-1);
     vec.push_back(-1);
   }

   cout<<"Starting and Ending index return of value ="<<tar<<" START ("<<vec[0]<<")"<<" END ("<<vec[1]<<")";

    return 0;
}