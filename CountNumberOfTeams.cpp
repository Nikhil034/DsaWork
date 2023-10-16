#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a size of array=";
    cin>>n;

   int rating[n],i,j,k,count=0;

   for(i=0;i<n;i++)
   {
    cin>>rating[i];
   }

   for(i=0;i<n;i++)
   {
    for(j=i+1;j<n;j++)
    {
        for(k=j+1;j<n;j++)
        {
            if(rating[i]<rating[j] && rating[j]<rating[k] || rating[i]>rating[j] && rating[j]>rating[k])
            {
                count++;
            }
        }
    }
   }

   cout<<"\nMAXIMUM PAIR RETURN IS="<<count;



    return 0;
}