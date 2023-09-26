#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],ans=1;

   for(int i=0;i<n;i++)
   {
     cin>>arr[i];
   }

   for(int i=0;i<n;i++)
   {
     ans=ans*arr[i];
   }
  
  if(ans<0)
  {
    cout<<"NEGATIVE!";
  }
  else if(ans>0)
  {
    cout<<"POSITIVE!";
  }
  else
  {
    cout<<"ZERO!";
  }


    return 0;
}