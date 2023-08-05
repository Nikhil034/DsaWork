#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    vector<int>vec;
    vector<int>vec2;
    int max=0;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(5);
    vec.push_back(6);
    int kth;
    

    

    for(int i=0;i<vec.size();i++) // 0 1 2 3 4
    {
    
       max=vec[0];
       for(int j=0;j<vec.size();j++) 
        {
           if(max<vec[j])
           {
            max=vec[j];
           }
           
        }

        vec2.push_back(max);
        vec.erase(std::remove(vec.begin(), vec.end(), max), vec.end());

      
    }

    for(int i=0;i<vec2.size();i++)
    {
        cout<<vec2[i]<<" ";
    }

   cout<<"Enter Your kth element=";
   cin>>kth;

   for(int i=0;i<vec2.size();i++)
   {
    if(i+1==kth)
    {
        cout<<"Kth element value is="<<vec2[i];
    }
   }



    return 0;
}