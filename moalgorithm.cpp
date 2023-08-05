#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int>vec;
    vec.push_back(1);
    vec.push_back(1);    
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(8);

   int f1=0,f2=4,sum1=0;
   int f11=1,f22=3,sum2=0;
   int f33=2,f44=4,sum3=0;

   for(int i=f1;i<=f2;i++)
   {
    sum1=sum1+vec[i];
   }

   cout<<"\nFirst query of ["<<f1<<","<<f2<<"]"<<"is="<<sum1;

    for(int i=f11;i<=f22;i++)
   {
    sum2=sum2+vec[i];
   }

   cout<<"\nSecond query of ["<<f11<<","<<f22<<"]"<<"is="<<sum2;


    for(int i=f33;i<=f44;i++)
   {
    sum3=sum3+vec[i];
   }

   cout<<"\nThird query of ["<<f33<<","<<f44<<"]"<<"is="<<sum3;





    return 0;
}