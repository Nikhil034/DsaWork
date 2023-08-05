#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[5]={2, 3, 4, 5, 6};
    int coun=0;
    vector<int>vec;

    for(int i=0;i<5;i++)
    {
       for(int j=i;j<5;j++)
       {
          if(arr[i]>arr[j])
          {
            coun++;
          }
       }
    }

   cout<<"Array of inversion counter is-->"<<coun;

   

    return 0;
}