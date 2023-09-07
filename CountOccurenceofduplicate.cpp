#include<iostream>
using namespace std;

int main(){
    int n,tar,count=0;
    cout<<"Enter size of array=";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cout<<"Enter index "<<i<<"value= ";
        cin>>arr[i];
    }

    cout<<"Enter a target value=";
    cin>>tar;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==tar)
        {
            count++;
        }
    }

 
  for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" ";
    }

    cout<<"Target value "<<tar<<" occurs "<<count<<" times ";
   

    return 0;
}