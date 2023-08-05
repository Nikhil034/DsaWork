#include<iostream>
using namespace std;

int main(){


    int arr[5],i,j,flag=0;

    for(i=0;i<5;i++)
    {
        cout<<"Enter a value=";
        cin>>arr[i];
    }

    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(arr[i]==arr[j])
            {
               flag=1;
               cout<<"Duplicate found return true....";
               break;
            }
            else
            {
                continue;
            }

        }
    }


    if(flag==0)
       cout<<"No duplicate found return false...";
   
    
    return 0;
}