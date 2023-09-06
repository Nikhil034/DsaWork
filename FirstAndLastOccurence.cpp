#include<iostream>
using namespace std;

int main(){
    int n,frst=0,last=0,tar,flag=0;
    cout<<"Enter a size of array=";
    cin>>n;

    int arr[n];

   for(int i=0;i<n;i++)
   {
    cout<<"Enter a value=";
    cin>>arr[i];
   }

   cout<<"Enter a target element=";
   cin>>tar;


   for(int i=0;i<n;i++)
   {
    if(arr[i]==tar)
    {
        frst=i;
        break;
    }
    else
    {
        flag=1;
    }
   }

    for(int i=frst+1;i<n;i++)
   {
    if(arr[i]==tar)
    {
        last=i;
        
    }
   }

   
   if(flag==1)
   {
    cout<<"Element not found in the array!";
   }
   else
   {
   cout<<"First occurence of "<<tar<<" is :"<<frst;
   cout<<"Last occurence of "<<tar<<" is :"<<last;
   }




    return 0;
}