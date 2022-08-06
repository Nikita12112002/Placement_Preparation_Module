class Solution {
public:
    int dfs(vector<int>&nums , int i, int prev , int n ,vector<vector<int>>dp)
    {
        // gives memory exceeded because of constraints 10^5 and we are creating dp vector of 10^5+ 10^5 = 10^10;
        if(i==n)
            return 0;
        
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        
        int notpick = dfs(nums,i+1,prev,n,dp);
    
        int pick =0;
        if(prev==-1 || nums[i]>nums[prev])
           pick = 1+dfs(nums,i+1,i,n,dp);
        
        return dp[i][prev+1]=max(pick ,notpick);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return dfs(nums,0,-1,n,dp);
        
    }
};