#include<iostream>

using namespace std;

int main(){
    
    int arr[10],min=0,max=0,i;

    for(i=0;i<10;i++)
    {
        cout<<"Enter a value for"<<i<<"=";
        cin>>arr[i];
    }

    //Base case

    min=arr[0];
    max=arr[1];

    for(i=0;i<10;i++)
    {
        if(min>arr[i])
          {
            min=arr[i];
          }

        if(max<arr[i])
        {
            max=arr[i];
        }  
    }

    for(i=0;i<10;i++)
    {
        cout<<"\n"<<arr[i]<<" ";
    }

    cout<<"\nMinimum value in array is="<<min;
    cout<<"\nMaximum value is arrays is="<<max;

    return 0;
}