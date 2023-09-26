#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],target,i,count=0;

   for(i=0;i<n;i++)
   {
    cin>>arr[i];
   }

   cout<<"Enter target value=";
   cin>>target;

   for(i=0;i<n;)
   {
     if(arr[i]+arr[i+1]==target)
     {
        count++;
        i+=2;
     }
     else
     {
        i++;
     }

   }

   cout<<"COUNT FOR YOUR ARRAY IS ="<<count;

    return 0;
}