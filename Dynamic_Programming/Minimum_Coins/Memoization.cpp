int dfs(vector<int>&nums , int i , int tar,vector<vector<int>>&dp)
{
    if(i==0)
    {
        if(tar%nums[i]==0)
            return tar/nums[i];
        else 
            return 1e9;
     }
    
    if(dp[i][tar]!=-1)
        return dp[i][tar];
    int notpick = dfs(nums,i-1,tar,dp);
    int pick = 1e9;
    if(nums[i]<=tar)
        pick = 1+dfs(nums,i,tar-nums[i],dp);
    return dp[i][tar] = min(pick,notpick);
}
int minimumElements(vector<int> &nums, int x)
{
    // Write your code here.
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
    int ans = dfs(nums ,n-1 , x,dp);
    if(ans>=1e9)
        return -1;
    else
        return ans;
}