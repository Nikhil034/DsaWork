#include<iostream>
using namespace std;

int FirstRepeatElement(int a[],int size)
{
    int repeat;
    for(int i=0;i<size;i++)
    {
       repeat=a[i];
       for(int j=1;j<size;j++)
       {
        if(repeat==a[j])
        {
            repeat=a[j];
        }
           
       }

    }
    return repeat;
}

int main(){
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"index of :"<<i<<" = ";
        cin>>arr[i];
    }

    cout<<FirstRepeatElement(arr,n);
    return 0;
}