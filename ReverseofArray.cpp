#include<iostream>
using namespace std;

int main(){
    
    int arr[5],i;

    for(i=0;i<5;i++)
    {
        cout<<"Enter value for position "<<i<<"=";
        cin>>arr[i];
    }
    cout<<"\n Original Array";
    for(i=0;i<5;i++)
    {
        cout<<"\n"<<arr[i]<<" ";
    }

     cout<<"\n Reverse of Array";

    for(i=4;i>=0;i--)
    {
        cout<<"\n"<<arr[i];
    } 

    return 0;
}