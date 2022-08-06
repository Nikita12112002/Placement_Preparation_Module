class Solution {
public:
    int dfs(vector<int>&nums , int i, int prev , int n)
    {
        if(i==n)
            return 0;
        
        int notpick = dfs(nums,i+1,prev,n);
    
        int pick =0;
        if(prev==-1 || nums[i]>nums[prev])
           pick = 1+dfs(nums,i+1,i,n);
        
        return max(pick ,notpick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        return dfs(nums,0,-1,n);
        
    }
};