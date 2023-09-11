#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array=";
    cin>>n;

    int arr[n],tar;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter a target value=";
    cin>>tar;

    vector<int>vec;

   for(int i=0;i<n;i++)
   {
     for(int j=i+1;j<n;j++)
     {
        if(arr[i]+arr[j]==tar)
        {
           vec.push_back(i);
           vec.push_back(j);
        }
     }
   }

   for(int j=0;j<vec.size();j++)
   {
    cout<<vec[j]<<" ";
   }


    return 0;
}