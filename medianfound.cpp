#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[4]={2, 3, 5, 8};
    int b[6]={10, 12, 14, 16, 18, 20};
    vector<int>vec1;
    int evenans,cn,index;

    //Step 1 :- contacte both into one vector

    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        vec1.push_back(a[i]);
    }
    for(int k=0;k<sizeof(b)/sizeof(b[0]);k++)
    {
        vec1.push_back(b[k]);
    }

    //Step 2 :- Sort that vector

     sort(vec1.begin(),vec1.end());

     for(int j=0;j<vec1.size();j++)
     {
        cout<<vec1[j]<<" ";
     }

    //Step 3 :- count how many element are there in vector

     cn=vec1.size();

    //Step 4 :- divide by 2 and get index and based on that index return a value from vector

    index=(cn/2)-1;
    cout<<index;

    //Step 5 :- print a median value of vector elements

    if(index%2==0)
    {
      evenans=(vec1[index]+vec1[index+1])/2;
      cout<<"Median value="<<evenans;
    }
    else
    {
      cout<<"Median value is="<<vec1[index];
    }


    return 0;
}