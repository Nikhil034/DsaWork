#include<iostream>
using namespace std;

int main(){
    int n;

    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],count=0,i,j,sum=0;

    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        cin>>arr[i];
    }

   for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
   {
    
      for(j=i+1;j<sizeof(arr)/sizeof(arr[0]);j++)
      {
        sum=arr[i]+arr[j];

       if(sum%60==0)
       {
        count++;
       }

      }
     
   }


   cout<<"TOTAL PAIR THAT DIVIDE BY 60 = "<<count;

    return 0;
}