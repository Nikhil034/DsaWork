#include<iostream>
using namespace std;

int main(){
    int n,count=0;
    cout<<"Enter a size=";
    cin>>n;

    int arr[n],tmp;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter index value"<<i<<"=";
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {   
              tmp=arr[i];
              arr[i]=arr[j];
              arr[j]=tmp;
              count++;
               
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"Inversion count is="<<count;


    return 0;
}