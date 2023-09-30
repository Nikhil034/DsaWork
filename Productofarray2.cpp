#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[4]={1,2,3,4};
    vector<int>vec;

    int sum=1,ele;

    for(int i=0;i<4;i++)
    {
        ele=arr[i];

        for(int j=0;j<4;j++)
        {
            if(arr[j]==ele)
            {
                continue;
            }
            else
            {
                sum=sum*arr[j];
            }
        }
        vec.push_back(sum);
        sum=1;
    }

    for(int k=0;k<vec.size();k++)
    {
        cout<<vec[k]<<" ";
    }

    return 0;
}