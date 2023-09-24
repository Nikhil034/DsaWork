#include<iostream>
using namespace std;

int main(){
    int n,count=0;
    cout<<"Enter your length=";
    cin>>n;

   for(int i=2;i<=n;i++)
   {
     if(i%i==0 && i%2!=0)
     {
      count++;
     }
   }

   cout<<count;

    return 0;
}