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
           cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"----Reverser matrix print----\n";


    for(int i=2;i>=0;i--)
    {
        for(int k=0;k<3;k++)
        {
            cout<<arr[i][k]<<" ";
        }
        cout<<"\n";
    }

 
    int g=0;
    for(int i=2;i>=0;i--)
    {
        for(int k=0;k<3;k++)
        {
            arr[k][g]=arr[i][k];
        }
        g+=1;
        cout<<"\n";
    }

    cout<<"----Rotate image----\n";

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