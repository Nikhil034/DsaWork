#include<iostream>
using namespace std;

int main(){
    
    int arr[3][3];
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=0;k<3;k++)
                {
                    arr[i][k]=0;
                    arr[k][j]=0;
                }
            }
        }
        cout<<"\n";
    }

     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}