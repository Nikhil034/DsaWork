#include<iostream>
using namespace std;

int main(){
    int arr[4]={1, 2, 3, 5};
    int count[5]={0,0,0,0,0},val;

    for(int i=0;i<4;i++)
    {
       for(int k=0;k<=5;k++)
       {

         if(k==arr[i])
         {
            count[k]=1;
            break;
         }

       }
        
    }

    for(int i=0;i<5;i++)
    {
        cout<<count[i]<<" ";
    }
     for(int i=1;i<5;i++)
    {
       if(count[i]==0)
       {
         val=i;
         break;
       }
    }

   cout<<"Missing value="<<val;



    return 0;
}