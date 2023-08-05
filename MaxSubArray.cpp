#include<iostream>
using namespace std;

int main(){
    
    int arr[5],i,psum=0,nsum=0;

    for ( i = 0; i < 5; i++)
    {
        cout<<"Enter a value=";
        cin>>arr[i];
    }

    for(i=0;i<5;i++)
    {
       if(arr[i]<0)
         nsum+=arr[i];
       else
         psum+=arr[i];  
            
    }

    cout<<"Sum of subarray is="<<psum+nsum;
    
    return 0;
}