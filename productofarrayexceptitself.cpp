#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[5]={10,3,5,6,2};
    vector<int>vec;
    int self,sum=1,last;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        self=arr[i];

        for(int k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
        {
           if(arr[k]==self)
          {
             continue;
          }
          else
          {
           sum=sum*arr[k];
          }
        }
        vec.push_back(sum);
        sum=1;

    }

   cout<<"-------Array Element value display------\n";
  
   for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
       last=sizeof(arr)/sizeof(arr[0]);
       if(i==last-1)
       {
        cout<<arr[i];
       }
       else
       {
       cout<<arr[i]<<","<<" ";
       }

   }

   cout<<"\n-------Array Product value display------\n";

   for(int i=0;i<vec.size();i++)
   {

        last=vec.size()-1;

        if(i==last)
        {
            cout<<vec[i];
        }
        else
        {
         cout<<vec[i]<<","<<" ";
        }
        
   }




    return 0;
}