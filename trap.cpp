#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        
        }
        return water;
    }
};


int main(){
    
    Solution sb;
    vector<int>vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(5);

   cout<<sb.trap(vec);
    return 0;
}