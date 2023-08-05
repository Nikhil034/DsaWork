#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> vec;
    vector<int> vec2;
    int lessbuy=0;
    int maxbuy=0;
    int day=0;
    int totalprofit=0;
    int max=0;
   

    vec.push_back(7);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(9);

    for(int i=0;i<vec.size();i++)
    {
        lessbuy=vec[i];

        for(int j=i+1;j<vec.size();j++)
        {
           if(lessbuy<vec[j])
           {
              maxbuy=vec[j];
              totalprofit=maxbuy-lessbuy;
              vec2.push_back(totalprofit);
           }
          
        }
    }


    if(vec2.size()>0)
    {
        
        max=vec2[0];
        for(int i=0;i<vec2.size();i++)
        {
           if(max<vec2[i])
           {
            max=vec2[i];
           }
        }

        cout<<"Total Profit is="<<max;
    }
    else
    {
        cout<<"No Transaction profit is="<<max;
    }

     
   


    return 0;
}