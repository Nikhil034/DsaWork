#include<iostream>
using namespace std;

int main(){
    int arr[4][4];

   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    {
        cout<<"Enter a  value:-";
        cin>>arr[i][j];
    }
   }
   
   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }


   cout<<"----- 90 Degree Rotate ----\n";
   int n=3;
   int arr1[4][4];

   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    {
        arr1[j][n]=arr[i][j];
    }
    n--;
   }

     for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    {
        cout<<arr1[i][j]<<" ";
    }
    cout<<"\n";
   }

    return 0;
}