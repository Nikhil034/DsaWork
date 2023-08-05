#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[6]={5,5,10,100,10,5};
    int max=arr[0];
    int index=0;

    for(int k=0;k<sizeof(arr)/sizeof(arr[0]);k++)
    {
        if(max<arr[k])
        {
            max=arr[k];
            index=k;
        }
    }
    
    cout<<"Maximum element with index is="<<max<<" "<<index;
    int ahead=index+1;
    int behind=index-1;
    int count=max;

    ahead=ahead+1;
    behind=behind-1;

    count+=arr[ahead]+arr[behind];
    cout<<"Answer is="<<count;


    return 0;
}