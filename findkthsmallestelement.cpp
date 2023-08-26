#include<iostream>
using namespace std;

int Findkthsmallest(int arr[],int size,int kth)
{
    int tmp,count=0;
    
    if(kth>size)
    {
        return -1;
    }

    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[i])
            {
              tmp=arr[i];
              arr[i]=arr[j];
              arr[j]=tmp;
            }
        }
    }
    return arr[kth-1];
}

int main(){
    int n,kth;
    cout<<"Enter a size of array=";
    cin>>n;

   int arr[n];

   for(int i=0;i<n;i++)
   {
    cout<<"index: "<<i<<" = ";
    cin>>arr[i];
   }

   cout<<"Enter kth smallest element you want=";
   cin>>kth;

  cout<<Findkthsmallest(arr,n,kth);

    return 0;
}