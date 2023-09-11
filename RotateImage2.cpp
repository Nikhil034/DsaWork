#include<iostream>
using namespace std;

int main(){
    int arr[3][3],newarr[3][3],i,j,k=2;

   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
        cin>>arr[i][j];
    }
   }

   cout<<"\n---------ORIGINAL ARRAY--------\n";

     for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
   }

  
   for(i=0;i<3;i++)
   {
     for(j=0;j<3;j++)
     {
        newarr[j][k]=arr[i][j];
     }
     k--;
   }

    cout<<"\n---------ROTATE IMAGE--------\n";

      for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
        cout<<newarr[i][j]<<" ";
    }
    cout<<"\n";
   }







    return 0;
}