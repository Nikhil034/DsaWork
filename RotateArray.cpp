#include<iostream>
using namespace std;

int main(){
    int n,rt,val;
    cout<<"Enter a size of array=";
    cin>>n;

   int arr[n];

   for(int i=0;i<n;i++)
   {
     cout<<"Enter a value=";
     cin>>arr[i];
   }

   cout<<"How many type you rotate=";
   cin>>rt;


   for(int k=0;k<rt;k++)
   {
    val=arr[n-1];

     for(int j=n-1;j>=1;j--)
     {
        arr[j]=arr[j-1];
     }
     arr[0]=val;
   }

   for(int i=0;i<n;i++)
   {
    cout<<arr[i]<<" ";
   }
 
    return 0;
}