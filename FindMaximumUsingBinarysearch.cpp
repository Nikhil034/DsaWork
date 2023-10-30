#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

   int arr[n];
   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }

   int left=0;
   int right=sizeof(arr)/sizeof(arr[0])-1;
   int mid=(left+right)/2;


   cout<<"Maximum number is="<<arr[right];





    return 0;
}