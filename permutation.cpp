class Solution {
public:
   void per(int i,set<vector<int>>&s,vector<int>&nums)
        {
            if(i>=nums.size())
            {
                s.insert(nums);
                return;
            }
            for(int ind=i;ind<nums.size();ind++)
            {
                swap(nums[i],nums[ind]);
                per(i+1,s,nums);
                swap(nums[i],nums[ind]);
            }
        }
    vector<vector<int>> permute(vector<int>& nums) {
     set<vector<int>> s;
        per(0,s,nums);
        vector<vector<int>> vc(s.begin(),s.end());
        return vc;
     
        
    }
};