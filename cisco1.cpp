#include<iostream>
using namespace std;

int main(){
    
    int arr[12],dp=0,rate=2,max_rate=10,ps=0,pl=0;
    arr[1]=8;
    arr[2]=0;
    arr[3]=0;
    arr[5]=0;
    arr[4]=9;
    arr[6]=7;
    arr[7]=0;
    arr[8]=0;
    arr[9]=0;
    arr[10]=0;
    arr[11]=0;

  int size=sizeof(arr)/sizeof(arr[0]);

  for(int i=1;i<=size+1;i++)
  {
    
    if(arr[i]!=0)
    {
        ps=ps+arr[i];

        if(ps>max_rate)
        {
            dp+=ps-max_rate;
            ps=10;

        }
    }
    else
    {
        ps=ps-rate;
    }

  }

 

  cout<<"Drop packets="<<dp;

    return 0;
}