// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
   
   int n=0,k,p,j;
   
   cin>>n;
   cin>>k;
   cin>>p;
   
   int arr[k];
   
   for(j=0;j<n;j++)
   {
       cin>>arr[j];
   }
   
  int frst=0,scd=0,res=0,count=0;
   
  for(int x=0;x<n;x++)
  {
      frst=arr[x]+arr[x+1];
      scd=(arr[x]*arr[x])+(arr[x+1]*arr[x+1]);
      
      res=frst*scd;
      
      if(res%k==p){
          count++;
      }
      
      
  }
  
  cout<<count;

    return 0;
}