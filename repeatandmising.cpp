#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    

    vector<int> vec;
    int repeat=0,mis=0;
    int rep=0;
    int cr=0,nt=0;
    vec.push_back(10);
    vec.push_back(9);
    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(7);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(6);


    sort(vec.begin(), vec.end());
 
    for(int i=0;i<vec.size();i++)
    {
      cr=vec[i];

      if(cr!=vec[i+1])
      {
        nt=0;
      }
      else
      {
        rep=vec[i];
        nt=vec[i]+1;
        break;

      }
    }

    cout<<"Repeat Number is="<<cr;
    cout<<"\nMising Number is="<<nt;


//  int tmp=0;
//   for(int i=0;i<vec.size();i++)
//   {
//     for(int j=i;j<vec.size();i++)
//     {
//          if(vec[i]<vec[j+1])
//          {
//             tmp=vec[i];
//             vec[i]=vec[j];
//             vec[j]=tmp;
//          }
//     }
//   }

//   for(int i=0;i<vec.size();i++)
//   {
//     cout<<vec[i]<<" ";
//   }
    return 0;
}