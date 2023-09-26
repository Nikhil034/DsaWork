#include<iostream>
using namespace std;

int main(){
    int low,high,count=0;

   cout<<"Enter a low value=";
   cin>>low;

   cout<<"Enter a high value=";
   cin>>high;

   for(int i=low;i<=high;i++)
   {
    if(i%2!=0)
    {
        count++;
    }
   }

   cout<<"ODD NUMBER COUNT IS ="<<count;



    return 0;
}