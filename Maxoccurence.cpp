#include<iostream>
using namespace std;

int main(){
    int arr[10]={4,4,3,4,1,2,1,0,1,1},mx,count=0;
    mx=arr[0];

   for(int i=0;i<10;i++)
   {
    if(mx<arr[i])
    {
        mx=arr[i];
    }
   }
   cout<<"Maximum value="<<mx;

   for(int i=0;i<10;i++)
   {
     if(mx==arr[i])
     {
        count++;
     }
   }

   cout<<"Maximum value is ="<<mx<<"and occurence is "<<count<<"times!";
    

    return 0;
}