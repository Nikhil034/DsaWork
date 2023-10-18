#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n],total=0,target=0,count=0;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int k=0;k<n;k++)
    {
        total+=arr[k];
        target+=k+1;


        if(total==target){
            count++;
        }
    }

    cout<<"RETURN VALUE IS="<<count;

    

    return 0;
}