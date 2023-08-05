#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int>vec;
    vector<int>vec2;
    vec.push_back(-1);
    vec.push_back(1);
    vec.push_back(0);
    vec.push_back(-3);
    vec.push_back(3);

    int sum=vec[0];
    int osum=vec[0];

    for(int i=1;i<vec.size();i++)
    {
        sum=sum*vec[i];

        for(int j=i+1;j<vec.size();j++)
        {
            osum=vec[i]*vec[j];
            vec2.push_back(osum);
        }
    }

    vec2.push_back(sum);
    int tmp=0;

   

    for(int i=vec2.size()-1;i>=0;i--)
    {
        cout<<vec2[i]<<" ";
    }
    return 0;
}