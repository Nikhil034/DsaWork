#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st=nums.size();
        
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                return i;
            }
        }
        return -1;
        
    }
};

int main(){
    
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(21);
    vect.push_back(22);
    Solution sb;
    cout<<sb.search(vect,222);
  

    return 0;
}
