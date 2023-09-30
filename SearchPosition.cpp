#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Entet a size of array=";
    cin>>n;

    int arr[n],tar,index;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Enter a target value=";
    cin>>tar;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==tar)
        {
           index=i;
           break;
        }
        else if(tar<arr[i])
        {
            index=i;
            break;
        }
        else
        {
           index=i+1;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"\nTARGET VALUE INDEX FIT IS ="<<index;
    return 0;
}