#include<iostream>
using namespace std;

int main(){
    int arr[9]={1, 2, 3, 4, 6, 7, 9, 8, 10},mis=0,n;
    n=0;

    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    { 
       
       if(arr[i]!=i+1)
       {
        mis=i+1;
        break;
       }
       
        
    }

    cout<<"Missing number is="<<mis;

    return 0;
}