#include<iostream>
using namespace std;


int FindUniqueLarget(int arr[],int n)
{
   int max=arr[0],count=1;

   for(int i=0;i<n;i++)
   {
     if(max<arr[i])
      max=arr[i];
   }

   for(int k=0;k<n;k++)
   {
    if(max==arr[k])
      count++;
   }

   if(count>2)
    return 0;
   else 
    return 1;
  
}

int main(){
    
    int n;
    cout<<"Enter a size=";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"index:"<<i<<" = ";
        cin>>arr[i];
    }

    if(FindUniqueLarget(arr,n))
    {
        cout<<"YES UNIQUE LARGEST !";
    }
    else
    {
        cout<<"NO UNIQUE LARGEST !";
    }

    return 0;
}