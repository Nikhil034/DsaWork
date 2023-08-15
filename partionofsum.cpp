#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[3]={1,3,5};
    vector<int>vec;
    int max=arr[0];
    int sum=0,flag=0;

    for(int i=0;i<3;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    cout<<"Maximum value is="<<max;


   for(int k=0;k<3;k++)
   {
    if(arr[k]==max)
    {
        continue;
    }
    else
    {
        sum+=arr[k];
        if(sum==max)
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
        
    }
   }
   cout<<sum;

  if(flag){
    cout<<"YES,PARTITION EQUAL TO SUM";
  }
  else{
     cout<<"NO,PARTITION EQUAL TO SUM";
  }

    return 0;
}